cmake_minimum_required(VERSION 3.25)
project(C__Algorithm)

set(CMAKE_CXX_STANDARD 17)


add_executable(main main.cpp Array/alphabet.cpp Array/roomnumber.cpp)
add_executable(normal Basic/normal.cpp Basic)
add_executable(fastsum Basic/fastsum.cpp Array/array.cpp Array/array.h)
add_executable(array Array/array.cpp)
add_executable(alphabet Array/alphabet.h Array/alphabet.cpp Array/roomnumber.cpp)
add_executable(roomnumber Array/roomnumber.cpp)
add_executable(linkedlist LinkedList/linkedlist.cpp)
add_executable(editor LinkedList/editor.cpp)
add_executable(stack Stack/stack.cpp)
add_executable(Quene Queue/Queue.cpp)
add_executable(implQueue Queue/implQueue.cpp)
add_executable(Deque Deque/Deque.cpp)
add_executable(balanceworld Deque/balanceworld.cpp)
add_executable(picture Bfs/picture.cpp)
add_executable(maze Bfs/maze.cpp)
add_executable(hanoiTower Recursion/hanoiTower.cpp)
add_executable(keylogger LinkedList/keylogger.cpp)
add_executable(dyschromatopsia Bfs/dyschromatopsia.cpp)
add_executable(cat Basic/sort.cpp)
add_executable(count Array/count.cpp)
add_executable(ac Deque/ac.cpp Deque/ac.cpp swea/KillFly.cpp)
add_executable(bank atm.cpp)
add_executable(coldCabbage Bfs/coldCabbage.cpp)
add_executable(knightMove Bfs/knightMove.cpp)
add_executable(breakWall Bfs/breakWall.cpp)
add_executable(termProject Bfs/termProject.cpp)
add_executable(soomba Bfs/soomba.cpp)
add_executable(soombaThree Bfs/soombaThree.cpp)
add_executable(monkeyHopes Bfs/monkeyHopes.cpp)
add_executable(colorPaper Recursion/colorPaper.cpp)
add_executable(nandmFive BackTracking/nandm/nandmFive.cpp)
add_executable(nandmSix BackTracking/nandm/nandmSix.cpp)
add_executable(nandmEight BackTracking/nandm/nandmEight.cpp)
add_executable(nandmTwelve BackTracking/nandm/nandmTwelve.cpp)
add_executable(sevenSisters BackTracking/sevenSisters.cpp)
add_executable(forTest forTest.cpp)
add_executable(makeLine Sort/makeLine.cpp)
add_executable(NormalBackpack DP/NormalBackpack.cpp)
add_executable(BackpackTwo DP/BackpackTwo.cpp)
add_executable(TilingTwo DP/TilingTwo.cpp)
add_executable(Lcs DP/Lcs.cpp)
add_executable(coin DP/coin.cpp)
add_executable(TImeMachine Graph/Bellman-Ford/TImeMachine.cpp)
add_executable(ShortestPath Graph/Dijkstra/ShortestPath.cpp)
add_executable(Floyd Graph/Floyd-Warshall/Floyd.cpp)
add_executable(MusicProgram Graph/MusicProgram.cpp)
add_executable(ConnectNetwork Graph/Union-Find/ConnectNetwork.cpp)
add_executable(SumOfNumber Algo_Dev/SumOfNumber.cpp)
add_executable(Sparse_Table Segment_Tree/Sparse_Table.cpp)
add_executable(Marriage Graph/Marriage.cpp)
add_executable(KillFly swea/KillFly.cpp)
add_executable(TwoNumberString swea/TwoNumberString.cpp)
add_executable(escape Bfs/second/escape.cpp)
add_executable(sum_section DP/sumSection.cpp)
add_executable(sumSection DP/sumSection.cpp)
add_executable(ContinuousSum DP/ContinuousSum.cpp)
add_executable(MeetingRoom Greedy/MeetingRoom.cpp)
add_executable(ChangYong_Village for_A/ChangYong_Village.cpp)
add_executable(Special_Magnet for_A/Special_Magnet.cpp)
add_executable(Switch for_A/Switch.cpp)
add_executable(Floyd2 Graph/Floyd-Warshall/Floyd2.cpp)
add_executable(Shark_elementary for_A/Shark_elementary.cpp)