// gangjian.c

#include <weapon.h>
inherit SWORD;
#define TMPF "/u/rcwiz/file_temp2002"

void create()
{
        set_name("钢剑", ({ "iron sword", "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄精工制成的钢剑，这种剑在将领之间非常流行。\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(25);
        setup();
}

void init()
{
       add_action("do_rwfile", "rw");
}

int do_rwfile(string arg)
{     
       object me = this_player();
       string src, dst, str1, str2;
       string str_temp, str_temp2, str_src;
       int i, count;

       seteuid(geteuid(me));
       if (! arg || sscanf(arg, "%s %s %s %s", src, str1, dst, str2 ) != 4)
                return notify_fail("指令格式错误！\n");
       src = resolve_path(me->query("cwd"), src);

       if (dst == "!")dst = src;
       if (str2 == "@")str2 = "";
       else
                dst = resolve_path(me->query("cwd"), dst); 

       if (file_size(src) == -1)
                return notify_fail("源文件名字错误。\n");

       if (file_size(dst) == -1)
                write("无目标文件，系统自动创建新文件。\n");
        
       // 另外一种解决方案，直接不读取包含str1的行

       if (str2 == "!")
       {
                write_file(TMPF, "", 1); 

                i = 1; 
                if (file_size(TMPF) == -1)
                       return notify_fail("建立临时文件错误。 \n");
                while (str_temp = read_file(src, i, 1))
                {     
                      // 去掉包含str1的行不读

                      if (strsrch(str_temp, str1) == -1)
                                if(! write_file(TMPF, str_temp))            
                                        return notify_fail("写入文件出错！\n");
                      i += 1;      
                }
       write(file_size(TMPF) + "\n");

       // 将临时文件temp_file2002写入新的文件，参数"!"为覆盖写入原来文件

       i = 1;
       write_file(src, "", 1);
       while(str_temp = read_file(TMPF, i, 1))
       {
               if(! write_file(src, str_temp))            
                                return notify_fail("写入新文件出错！\n");
                i += 1;
       }
       write("Done!\n");

       // 删除临时文件

       rm(TMPF);
       return 1;
       }

       // 替换str1为str2
       str_src = replace_string(str_src, str1, str2);
       if(write_file(dst, str_src, 1))
                write("成功写入文件！\n");
       else 
                write("写入失败。\n");
       return 1;
 

}



