/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004 by Witz Corporation, JAPAN
 * 
 *  Copyright (C) 2013 by Fan Wang(parai), China
 * 
 * The above copyright holders grant permission gratis to use,
 * duplicate, modify, or redistribute (hereafter called use) this
 * software (including the one made by modifying this software),
 * provided that the following four conditions (1) through (4) are
 * satisfied.
 * 
 * (1) When this software is used in the form of source code, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be retained in the source code without modification.
 *
 * (2) When this software is redistributed in the forms usable for the
 *    development of other software, such as in library form, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be shown without modification in the document provided
 *    with the redistributed software, such as the user manual.
 *
 * (3) When this software is redistributed in the forms unusable for the
 *    development of other software, such as the case when the software
 *    is embedded in a piece of equipment, either of the following two
 *    conditions must be satisfied:
 *
 *  (a) The above copyright notice, this use conditions, and the
 *      disclaimer shown below must be shown without modification in
 *      the document provided with the redistributed software, such as
 *      the user manual.
 *
 *  (b) How the software is to be redistributed must be reported to the
 *      TOPPERS Project according to the procedure described
 *      separately.
 *
 * (4) The above copyright holders and the TOPPERS Project are exempt
 *    from responsibility for any type of damage directly or indirectly
 *    caused from the use of this software and are indemnified by any
 *    users or end users of this software from any and all causes of
 *    action whatsoever.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 * THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 * TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 * INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 */

/*
 *	タスク管理モジュール
 */

#ifndef _TASK_H_
#define _TASK_H_

/*
 *  タスクIDの特殊な値の定義
 */
#define TSKID_NULL		((TaskType) UINT8_INVALID)	/* 無効ID */

/*
 *  タスク状態（tcb_stat）値の定義
 */
#define TS_RUNNABLE		READY				/* 実行状態，実行可能状態 */
#define TS_DORMANT		SUSPENDED			/* 休止状態 */
#define TS_WAITING		WAITING				/* 待ち状態 */

/*
 *  os_cfg.c, static configured information for tasks
 */
extern const UINT8	tnum_task;		/* number of the (basic & extend) task has been configured */
extern const UINT8	tnum_exttask;		/* number of the extend task has been configured */
extern const Priority	tinib_inipri[];		/* task init priority */
extern const Priority	tinib_exepri[];		/* task priority when start to execute */
extern const UINT8		tinib_maxact[];		/* task max activate count */
extern const AppModeType tinib_autoact[];	/* task autostart mode */
extern const FP			tinib_task[];		/* task entery */
extern const VP			tinib_stk[];		/* task stack buffer entry */
extern const UINT16		tinib_stksz[];		/* task stack buffer size */

/*
 *  os_cfg.c
 *
 *  used to manage tasks < tasks queue, state, proority, activate count >
 */
extern TaskType			tcb_next[];			/* task linker,indicate the next task in the queue */
extern UINT8			tcb_tstat[];		/* task state */
extern Priority			tcb_curpri[];		/* task current priority */
extern UINT8			tcb_actcnt[];		/* task current activate count */
extern EventMaskType	tcb_curevt[];		/* task current event has been set */
extern EventMaskType	tcb_waievt[];		/* task wait event */
extern ResourceType		tcb_lastres[];		/* task acquired resource recently */

/*
 *  help the scheduler to remember the current task in running state
 *
 *  when it is TKSID_NULL, no task is in ready state
 */
extern TaskType			runtsk;

/*
 *  help the scheduler to remember the next highest ready task  
 */
extern TaskType			schedtsk;

/*
 *  help the scheduler to remember the next high priority
 */
extern Priority			nextpri;

/*
 *  タスク管理モジュールの初期化
 */
extern void	task_initialize(void);

/*
 *  タスクの起動
 *
 *  対象タスク（tskid で指定したタスク）を起動する（休止状態から実行で
 *  きる状態に遷移させる．タスクの起動時に必要な初期化を行う．
 */
extern BOOL	make_active(TaskType tskid);

/*
 *  実行できる状態への移行
 *
 *  対象タスク（tskid で指定したタスク）を実行できる状態に遷移させる．
 *  対象タスクの優先度が，最高優先度タスク（schedtsk）の優先度よりも高
 *  い場合には，対象タスクを新しい最高優先度タスクとし，それまでの最高
 *  優先度タスクをレディキューの先頭に入れる．そうでない場合には，対象
 *  タスクをレディキューの末尾に入れる．対象タスクを最高優先度タスクと
 *  した場合に，TRUE を返す．
 */
extern BOOL	make_runnable(TaskType tskid);

/*
 *  最高優先順位タスクのサーチ
 *
 *  レディキュー中で最も優先順位の高いタスクをサーチし，それをレディ
 *  キューから外して，最高優先順位タスク（schedtsk）とする．実際には，
 *  レディキュー中の最高優先度が nextpri に設定されているためにサーチ
 *  は必要なく，優先度 nextpri のレディキューの先頭のタスクを最高優先
 *  順位タスクとする．レディキューのサーチは，そのタスクをレディキュー
 *  から外した後に nextpri を更新するために必要となる．このサーチに，
 *  ready_primap を用いる．
 *  この関数は，それまで実行状態であったタスクが待ち状態か休止状態に移
 *  行した時に，次に実行すべきタスクを選ぶために呼び出す．よってこの関
 *  数では，それまでの最高優先度タスクは無視する．
 */
extern void	search_schedtsk(void);

/*
 *  タスクのプリエンプト
 *
 *  自タスクを実行可能状態に移行させ，最高優先度タスクを実行状態にする．
 *  この関数から戻った後に，dispatch を呼び出して他のタスクへ切り替える
 *  ことを想定している．
 */
extern void	preempt(void);

#endif /* _TASK_H_ */
