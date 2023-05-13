To obtain a segment of k
 cells of black color, we need to paint all the white cells of the segment black. Then go through all the segments of length k
 (there are only n−k
) and choose such a segment among them that the number of white cells on it is minimal. You can quickly find out the number of white cells in the segment by prefix sums.
