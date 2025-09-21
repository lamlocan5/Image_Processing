
def mean_filter_valid(img, k=3, rounding=True):
    R, C = len(img), len(img[0])
    out = []
    for i in range(R - k + 1):
        row = []
        for j in range(C - k + 1):
            s = 0
            for u in range(k):
                for v in range(k):
                    s += img[i+u][j+v]
            m = s / (k*k)
            row.append(int(round(m)) if rounding else m)
        out.append(row)
    return out

def median_filter_valid(img, k=3):
    R, C = len(img), len(img[0])
    out = []
    for i in range(R - k + 1):
        row = []
        for j in range(C - k + 1):
            win = []
            for u in range(k):
                for v in range(k):
                    win.append(img[i+u][j+v])
            win.sort()
            row.append(win[len(win)//2])  
        out.append(row)
    return out

def print_mat(M):
    for r in M:
        print(*r)

# ---- DEMO với ma trận đề bài ----
I = [
    [2,7,3,0],
    [3,1,6,3],
    [0,1,3,5],
    [3,6,7,1],
]

print("Mean 3x3 (valid, làm tròn):")
print_mat(mean_filter_valid(I, 3, rounding=True))

print("\nMean 3x3 (valid, số thực):")
print_mat(mean_filter_valid(I, 3, rounding=False))

print("\nMedian 3x3 (valid):")
print_mat(median_filter_valid(I, 3))
