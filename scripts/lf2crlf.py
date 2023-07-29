import sys

def convert_lf_to_crlf(file): 
  with open(file, 'r') as f:
    context = f.read()
    
  context = context.replace('\n', '\r\n')

  with open(file, 'w') as f:
    f.write(context)

convert_lf_to_crlf(sys.argv[1])
