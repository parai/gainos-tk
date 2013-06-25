# -*- coding: utf-8 -*-
"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 *
 * GaInOS-Studio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * GaInOS-Studio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS-Studio. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: parai
 * Email: parai@foxmail.com
 * URL: https://github.com/parai/gainos-tk
 */
 """
 
import sys, os

def gappendpath():
    """This API Do what '#include "file.h"' do in C"""
    for dir in sys.path:
        if(os.path.isfile(dir+'/main.py')
           and os.path.isdir(dir+'/ui')
           and os.path.isdir(dir+'/config')):
            break;
    sys.path.append(dir+'/ui/forms');
    sys.path.append(dir+'/ui/classes');
    sys.path.append(dir+'/config');
    sys.path.append(dir+'/common');

def main(argc, argv):
    from PyQt4 import QtCore, QtGui
    from gainos_studio import mwgainostk
    app = QtGui.QApplication(argv);
    wMainWin = mwgainostk(argc,argv);
    wMainWin.show();
    sys.exit(app.exec_());

def gainos_test(oilfile,path):
    from config.gainos_tk_os_cfg import gainos_tk_os_cfg
    from oil_adapter import oil_gainos
    oscfg = gainos_tk_os_cfg('MC9S12');
    oil_gainos.to_oscfg(oilfile,oscfg)
    oil_gainos.post_process(oscfg)
    oscfg.gen(path);
    print "Generate file at %s OK!"%(path)

if __name__ == "__main__":
    gappendpath();
    if(len(sys.argv) == 4 and sys.argv[1] == '--test'):
        gainos_test(sys.argv[2],sys.argv[3])
    else:
        main(len(sys.argv),sys.argv);
