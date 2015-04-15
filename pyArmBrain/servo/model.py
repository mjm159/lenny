class Servo():
    MAX = 179
    MIN = 0

    def __init__(self, val=0, step_size=1):
        self.val = val
        self.step_size = step_size

    def update(self, step):
        if step < -0.2 and self.val + step >= self.MIN:
            self.val -= self.step_size
            return True
        elif step > 0.2 and self.val + step <= self.MAX:
            self.val += self.step_size
            return True
        return False

