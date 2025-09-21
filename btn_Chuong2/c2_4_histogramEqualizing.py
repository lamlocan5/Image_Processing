import sys
import numpy as np

def histogram_equalization(matrix, L = 8):
    m, n = matrix.shape
    total = m * n
    flat = matrix.flatten()
    hist = np.bincount(flat, minlength = L)
    probs = hist / total
    cdf = np.cumsum(probs)
    mapping = np.round((L-1)*cdf).astype(int)
    result = np.array([mapping[val] for val in flat])
    return result.reshape(matrix.shape)
    
def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    m, n = map(int, data[0:2])
    L = int(data[2])
    
    vals = list(map(int, data[3:]))
    matrix = np.array(vals).reshape(m,n)
    
    out = histogram_equalization(matrix, L)
    
    for row in out:
        print(" ".join(map(str, row)))
        

if __name__ == "__main__":
    main()