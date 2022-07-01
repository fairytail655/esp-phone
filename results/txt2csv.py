import os
import sys
import time
import pandas as pd

def main(argv):
    # 判断文件合法性
    files_name = []
    for arg in argv:
        if not os.path.isfile(arg):
            print("[%s] doesn't exist!" % arg)
            return
        file = os.path.split(arg)[-1].split('.')[0]
        files_name.append(file)

    # # 提取数据
    # data_dict = {}
    # last_line_count = 0
    # for i, arg in enumerate(argv):
    #     begin_flag = False
    #     data_list = []
    #     with open(arg, "r") as f:
    #         line = f.readline()
    #         while line:
    #             if 'app_main' in line:
    #                 if not begin_flag:
    #                     if 'Data' in line:
    #                         begin_flag = True
    #                 else:
    #                     if 'Data' in line:
    #                         break
    #                     else:
    #                         data_list.append(line.split()[-1])
    #             line = f.readline()
    #         if i != 0 and last_line_count != len(data_list):
    #             print(
    #                 "file line count don't match, [%s:%d] [%s:%d]" % \
    #                 (files_name[i-1], last_line_count, files_name[i], len(data_list))
    #             )
    #             return
    #         last_line_count = len(data_list)
    #         data_dict[files_name[i]] = data_list

    # 提取数据
    file_data_list = []
    for i, arg in enumerate(argv):
        begin_flag = False
        with open(arg, "r") as f:
            data_list = []
            line = f.readline()
            while line:
                if 'app_main' in line:
                    if not begin_flag:
                        if 'Data' in line:
                            begin_flag = True
                    else:
                        if 'Data' in line:
                            break
                        else:
                            data_list.append(line.split()[-1])
                line = f.readline()
        file_data_list.append(data_list)

    # 生成数据字典
    data_dict = {}
    for i, arg in enumerate(argv):
        data_list = file_data_list[i]
        for j in range(len(data_list[0].split(','))):
            file_name = files_name[i] + "_" + str(j)
            data_dict[file_name] = []
    for i, arg in enumerate(argv):
        data_list = file_data_list[i]
        for j in range(len(data_list)):
            line_list = data_list[j].split(',')
            for k in range(len(line_list)):
                file_name = files_name[i] + "_" + str(k)
                data_dict[file_name].append(line_list[k])

    # 写入csv文件
    out_file_name =time.strftime("%Y-%m-%d_%H:%M:%S.csv", time.localtime())
    data_frame = pd.DataFrame(data_dict)
    data_frame.to_csv(out_file_name, sep=',')

if __name__ == "__main__":
    main(sys.argv[1:])
