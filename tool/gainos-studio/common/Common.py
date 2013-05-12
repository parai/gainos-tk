# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
"""
#如果为True，则在每次生成代码是自动备份上一次生成的配置文件
#如果为False，则不备份，将直接覆盖，可能造成数据对视，慎用
File_BakeUp_On_Gen = False;

def TRUE(tr):
    if(tr==True):
        return 'TRUE';
    else:
        return 'FALSE';

def bool(s):
    if(s=='True'):
        return True;
    else:
        return False;

def gSTD_ON(s):
    if(s==True):
        return 'STD_ON';
    else:
        return 'STD_OFF';

def gcfindObj(list, name):
    """Global Common API to find an object in list by name"""
    for obj in list:
        if(name==obj.name):
            return obj;
    return None;

def gcfindModule(list, name):
    for md in list:
        if(md.module == name):
            return md;
    return None;
    
def gcbackup(file):
    import shutil 
    from time import localtime, time,strftime
    tm=localtime(time());
    file2=file+strftime("-%Y-%m-%d-%H-%M-%S",tm);
    shutil.copy(file, file2+'.bak'); 

def gcgetTime():
    from time import localtime, time,strftime
    tm=localtime(time());
    tm=strftime("%Y-%m-%d:%H-%M-%S",tm);
    return tm; 
