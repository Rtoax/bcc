# Copyright (c) CESTC, Co.
# Licensed under the Apache License, Version 2.0 (the "License")
import os
import sys
from importlib.metadata import distribution

package_name = "bcc"

if len(sys.argv) < 2:
    print("Error: No argument provided.", file=sys.stderr)
    print("Usage: python manifest.py <output text>", file=sys.stderr)
    sys.exit(1)

manifest_txt = sys.argv[1]

try:
    dist = distribution(package_name)
    location = dist.locate_file('')
    files = dist.files
    with open(manifest_txt, 'w', encoding='utf-8') as text:
        for f in files:
            text.write(f"{location}/{f}\n")
except:
    print(f"Error generate '{package_name}' manifest", file=sys.stderr)
    os.exit(1)
