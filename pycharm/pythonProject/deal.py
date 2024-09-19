from PIL import Image
import os


def resize_images(input_folder, output_folder, size):
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for filename in os.listdir(input_folder):
        if filename.endswith((".jpg", ".jpeg", ".png")):
            img = Image.open(os.path.join(input_folder, filename))
            img = img.resize(size, Image.Resampling.LANCZOS)
            img.save(os.path.join(output_folder, filename))


input_folder = 'player'
output_folder = 'player1'
size = (32, 66)  # 新尺寸

resize_images(input_folder, output_folder, size)
