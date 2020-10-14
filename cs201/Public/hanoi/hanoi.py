#!/usr/bin/env python3

class HanoiGame:
    def __init__(self, size = 7):
        self._size = size
        self._towers = [list(range(self._size, 0, -1)), [], []]
        self._work = 0

    def print_start(self):
        print("==== Start of Towers ==================")
        for tower in self._towers:
            print(tower)

    def get_towers(self, src_tower, dst_tower):
        if type(src_tower) is int:
            src_tower = self._towers[src_tower]
        if type(dst_tower) is int:
            dst_tower = self._towers[dst_tower]
        return src_tower, dst_tower

    def get_other_tower(self, src_tower, dst_tower):
        for t in self._towers:
            if t is not src_tower and t is not dst_tower:
                return t;

    def move_disk(self, src_tower, dst_tower):
        src_tower, dst_tower = self.get_towers(src_tower, dst_tower)
        if len(src_tower) == 0:
            print("Error: Cannot move from an empty tower.")
            return
        top_src_tower = src_tower[-1]
        if len(dst_tower):
            top_dst_tower = dst_tower[-1]

            if top_src_tower < top_dst_tower:
                top_src_tower = src_tower.pop(-1)
                dst_tower.append(top_src_tower)
            else:
                print("Error: Cannot move larger disk on top of a smaller disk.")
                return
        else:
            top_src_tower = src_tower.pop(-1)
            dst_tower.append(top_src_tower)

        self._work += 1

    def move_stack(self, num, src_tower, dst_tower):
        src_tower, dst_tower = self.get_towers(src_tower, dst_tower)
        other_tower = self.get_other_tower(src_tower, dst_tower)

        # Recursion Base Cases
        if num == 1:
            self.move_disk(src_tower, dst_tower)
            return
        elif num == 2:
            self.move_disk(src_tower, other_tower)
            self.move_disk(src_tower, dst_tower)
            self.move_disk(other_tower,dst_tower)
            return

        self.move_stack(num-1, src_tower, other_tower)
        self.move_disk(src_tower, dst_tower)
        self.move_stack(num-1, other_tower, dst_tower)

    def solve(self):
        print("##########################################################")
        print(f" Towers of Hanoi with {self._size} disks")
        print("##########################################################")

        self.move_stack(self._size, 0, 2)

        print("==========================================================")
        print(f" Solved in {self._work} moves. ")
        print("==========================================================")

if __name__ == "__main__":
    for number in range(1, 26):
        hg = HanoiGame(size = number)
        hg.solve()
