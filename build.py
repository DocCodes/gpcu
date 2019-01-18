#!/usr/bin/env python3

import os
import re
from datetime import datetime as dt

now = dt.now()
nowStr = now.strftime('%Y-%m-%d')
files = os.listdir('includes')
files.remove('all.hpp')
files.remove('gpcu.hpp')
filesCode = []
code = ''

includes = [
    'algorithm',
    'iomanip',
    'iostream',
    'sstream',
    'string',
    'regex'
]

for fi in files:
    lcCode = open(f'includes/{fi}', 'r').read()
    lcCode = re.sub(r'.*namespace gpcu {\n', '', lcCode, 0, re.MULTILINE + re.DOTALL)
    lcCode = re.sub(r'}  // namespace gpcu.*', '', lcCode, 0, re.MULTILINE + re.DOTALL)
    filesCode.append(lcCode)

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
    '\n'.join([f'#include <{i}>' for i in includes]),
    '',
    'namespace gpcu {',
    '\n'.join(filesCode),
    '}  // namespace gpcu',
    '',
    '#endif  // GPCU_HPP_',
    ''
])
open('includes/gpcu.hpp', 'w').write(code)
