
f = open("titles", 'r')
titles = []
counter = 1
for line in f.readlines():
    line = line.strip().split()
    if len(line) <= 1:
        continue
    if len(line) > 4:
        x = ''.join(line[:len(line)-4])
        line = line[len(line)-4:]
        line[0] = x + line[0]
    string = "{} {} {} {}".format(counter, line[0], line[2], line[3])
    # print(string)
    titles.append(string)
    counter += 1


tag_files = ["two_pointers","tree","top_k","linked_list","binary_search","ershuameiyou"]
idxs = []
not_founds = []
for tag_file in tag_files:
    not_found = []
    tag_idxs = []
    for line in open(tag_file, 'r'):
        line = ''.join(line.strip().split()[1:])
        # print(line)
        found = False
        for title in titles:
            if line in title:
                # print(title.split()[0])
                tag_idxs.append(title.split()[0])
                found = True
                break
        if not found:
            not_found.append(line)
    idxs.append(tag_idxs)
    not_founds.append(not_founds)
for tag_file in tag_files:
    print(tag_file),
print("")
max_rows = max([len(_) for _ in idxs])
# for idx in idxs:
#     print(idx)
for _ in range(max_rows):
    for tag_idxs in idxs:
        if _ < len(tag_idxs):
            print(tag_idxs[_]),
        else:
            print(-1),
    print("")

# =CONCATENATE(IF(SUMPRODUCT(COUNTIF($J$2:$J$300,A2)),CONCATENATE($J$1, ","),""),IF(SUMPRODUCT(COUNTIF($K$2:$K$300,A2)),CONCATENATE($K$1,","),""), IF(SUMPRODUCT(COUNTIF($L$2:$L$100,A2)),CONCATENATE($L$1,","),""), IF(SUMPRODUCT(COUNTIF($M$2:$M$100,A2)),CONCATENATE($M$1, ","),""), IF(SUMPRODUCT(COUNTIF($N$2:$N$100,A2)),CONCATENATE($N$1, ","),""),IF(SUMPRODUCT(COUNTIF($O$2:$O$300,A2)),CONCATENATE($O$1, ","),"") )