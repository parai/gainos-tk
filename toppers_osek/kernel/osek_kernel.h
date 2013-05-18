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

#ifndef _OSEK_KERNEL_H_
#define _OSEK_KERNEL_H_

/*
 *  カーネル内部共通のインクルードファイル
 */
#include "kernel.h"

/*
 *  カーネル内で使用するデータ型の定義
 */
#ifndef _MACRO_ONLY
typedef void		*VP;			/* 型が定まらないものへのポインタ */
typedef void		(*FP)(void);	/* プログラムの起動番地（ポインタ） */
typedef UINT8		Priority;		/* 優先度（タスク，ISR） */
typedef	UINT8		IPL;			/* 割込み優先レベル */
#endif /* _MACRO_ONLY */

#include "portable.h"
/*
 *  優先度の段階数の定義
 */
#define TNUM_PRIORITY	((Priority) 16)

/*
 *  一般的な定数の定義
 */
#define	NULL			((void *) 0)		/* 無効ポインタ */

/*
 *  優先度値の定義
 */
#define TPRI_MINTASK	((Priority) 0)		/* 最低タスク優先度 */
#define TPRI_MAXTASK	((Priority)(TNUM_PRIORITY - 1))
											/* 最高タスク優先度 */
#define TPRI_SCHEDULER	((Priority) 127)	/* スケジューラの優先度 */
#define TPRI_MINISR		((Priority) 128)	/* 最低割込み優先度 */
#define TPRI_NULL		((Priority) UINT8_INVALID)
											/* 無効優先度 */

/*
 *  イベントマスク値の定義
 */
#define EVTMASK_NONE	((EventMaskType) 0)	/* イベントなし */

/*
 *  アプリケーションモード値の定義
 */
#define APPMODE_NONE	((AppModeType) 0)	/* モードなし */

/*
 *  IPL値の定義
 */
#define IPL_ENA_ALL	((IPL) 0)		/* すべての割込みを許可 */

/*
 *  実行中のコンテキスト（callevel）の値の定義
 */
#define TCL_NULL		((UINT8) 0x00)	/* サービスコールを呼び出せない */
#define TCL_TASK		((UINT8) 0x01)	/* タスク */
#define TCL_ISR2		((UINT8) 0x02)	/* カテゴリ2 ISR */
#define TCL_ERROR		((UINT8) 0x04)	/* ErrorHook */
#define TCL_PREPOST		((UINT8) 0x08)	/* PreTaskHook，PostTaskHook */
#define TCL_STARTUP		((UINT8) 0x10)	/* StartupHook */
#define TCL_SHUTDOWN	((UINT8) 0x20)	/* ShutdownHook */


#ifndef _MACRO_ONLY
/*
 *  OS実行制御のための変数（osctl.c）
 */
extern UINT8		callevel;	/* 実行中のコンテキスト */
extern AppModeType	appmode;	/* アプリケーションモード */

/*
 *  OS内のクリティカルセクション操作関数
 */
Inline void	lock_cpu(void);		/* クリティカルセクション開始 */
Inline void	unlock_cpu(void);	/* クリティカルセクション終了 */

Inline void
lock_cpu(void)
{
	disable_int();
}

Inline void
unlock_cpu(void)
{
	enable_int();
}

/*
 *  エラーフック呼び出しのための宣言（osctl.c）
 *
 *  サービスコール内でエラーが発生した場合には，サービスコールへのパラ
 *  メータを _errorhook_par1～3 に設定した後，call_errorhook を呼び出す．
 *  call_errorhook へは，エラーコードとサービスコールのIDを渡す．
 */
extern void	call_errorhook(StatusType ercd, OSServiceIdType svcid);

/*
 *  ポストタスクフック/プレタスクフック呼び出しのための宣言（osctl.c）
 */
extern void	call_posttaskhook(void);
extern void	call_pretaskhook(void);

/*
 *  os_cfg.c
 */
extern void	object_initialize(void);

#endif /* _MACRO_ONLY */

/*
 *  拡張ステータスを標準に
 */
#ifndef BASIC_STATUS
#define EXTENDED_STATUS
#endif /* BASIC_STATUS */

#endif /* _OSEK_KERNEL_H_ */
