import sys
from PIL import Image

for infile in sys.argv[1:]:
	with Image.open(infile) as im:
		print(infile, im.format, f"{im.size}")
		region = im.crop((350, 160, 910, 1690))
		scaled = region.resize((75, 170))
		scaled.save("s" + infile)
