class point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def display(self):
        print('X = ',self.x)
        print('Y = ',self.y)
class dot(point):
    def __init__(self, x, y):
        self.p = point(x,y)
    def display(self):
        print("dot is a point")
        self.p.display()
        
class line:
    def __init__(self,p1,p2):
        p1.display()
        p2.display()
        self.p1 = p1
        self.p2 = p2
    def display(self):
        print("LINE = ")
        self.p1.display()
        self.p2.display()
    
        
d = dot(69,420)
p1 = point(1,2)
p2 = point(3,5)
l = line(p1,p2)
l.display()
#d.display()
