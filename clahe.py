import cv2
import matplotlib.pyplot as plt

clahe = cv2.createCLAHE(clipLimit=2,tileGridSize=(10,10))
cl1 = clahe.apply(img)
plt.subplot(132),plt.imshow(res,'gray')
plt.subplot(133),plt.imshow(cl1,'gray')

plt.show()
