#!/usr/bin/env python3
###
#  @file      build.py
#  @brief     Builds together all the separate headers into one main header.
#
#  @author    Evan Elias Young
#  @date      2019-01-17
#  @date      2019-01-29
#  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
##

import os
import re
from datetime import datetime as dt

now = dt.now()
nowStr = now.strftime('%Y-%m-%d')
files = os.listdir('includes')
files.remove('all.hpp')
files = [f for f in files if f.endswith('.hpp')]
filesCode = []
code = ''

baseInc = []
cInc = []
for fi in files:
    lcCode = open(f'includes/{fi}', 'r', encoding='utf-8').read()
    baseInc.extend(re.findall('#include <.*>', lcCode))
    lcCode = re.sub(r'.*namespace gpcu {\n', '', lcCode, 0, re.MULTILINE + re.DOTALL)
    lcCode = re.sub(r'}  // namespace gpcu.*', '', lcCode, 0, re.MULTILINE + re.DOTALL)
    filesCode.append(lcCode)

baseInc = list(set(baseInc))
cInc = baseInc.copy()
baseInc = [i for i in baseInc if not i.endswith('.h>')]
cInc = [i for i in cInc if i.endswith('.h>')]
baseInc.sort()
cInc.sort()

filesCode[-1] = filesCode[-1].rstrip()
code = '\n'.join([
    '//  gpcu.hpp',
    '//  gpcu',
    '//',
    f'//  Created by Evan Elias Young on {nowStr}.',
    f'//  Copyright {now.year} Evan Elias Young. All rights reserved.',
    '',
    '#ifndef GPCU_HPP_  // include guard',
    '#define GPCU_HPP_',
    '',
    '\n'.join(cInc),
    '',
    '\n'.join(baseInc),
    '',
    'namespace gpcu {',
    '\n'.join(filesCode),
    '}  // namespace gpcu',
    '',
    '#endif  // GPCU_HPP_',
    ''
])
open('gpcu.hpp', 'w', encoding='utf-8').write(code)
