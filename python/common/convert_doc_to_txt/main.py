#! /usr/bin/env python
import docx as docx
import docx2txt
import os
import docx
import subprocess
import sys

if len(sys.argv) < 2:
    sys.stderr.write("SYNONPSIS: %s file1 [file2] ...\n"%sys.argv[0])

for doc in sys.argv[1:]:
    subprocess.call(['soffice', '--headless', '--convert-to', 'docx', '--outdir', 'myoutputdir', doc])

# filename = "РЕГИСТРАЦИЯ СУСП-КВП.docx"

# print(os.listdir())


# def get_text(file_name: str):
#     doc = docx.Document(file_name)
#     return [para.text for para in doc.paragraphs]

help()
# print(get_text(filename))

