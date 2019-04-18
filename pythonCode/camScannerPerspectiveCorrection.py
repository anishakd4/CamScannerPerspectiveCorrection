import cv2
import numpy as np

#Read the book image
book  = cv2.imread("../assets/book.jpg")

#four corners of the book in the image
pts_book = np.array([[1456, 1580], [2237, 2048], [1417, 3668], [604, 2774]])

#general aspect ratio of books are 3:4 for so we choose the size (300, 400)
pts_correct = np.array([[0, 0], [299, 0], [299, 399], [0, 399]])

#calculate homography from book image to size(300, 400)
homorgaphyMat, status = cv2.findHomography(pts_book, pts_correct)

#warp book for perspective correction (300, 400)
result = cv2.warpPerspective(book, homorgaphyMat, (300, 400))

#create windows to display images
cv2.namedWindow("book", cv2.WINDOW_NORMAL)
cv2.namedWindow("correction", cv2.WINDOW_NORMAL)

#display images
cv2.imshow("book", book)
cv2.imshow("correction", result)

#press esc to exit the program
cv2.waitKey(0)

#close all the opened windows
cv2.destroyAllWindows()