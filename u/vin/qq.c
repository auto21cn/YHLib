// msn.c 信息生成器
// by vin

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "信息生成器" NOR, ({ "msg" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "
————————————————————————

可以使用 (" HIY "setrank" NOR ")来设定信息标题，缺省为查看当前
标题。如果添加(" HIY "none" NOR ")则设定回仪器预设标题。\n
使用 (" HIY "msn" NOR ")时将呼叫出信息，这时游戏中的所有玩家均
能看到该信息的发布。其中使用者的名字为" HIC "$N" NOR "，使用者
的id为" HIC "$I" NOR "，闪亮标记为" HIC "$S$" NOR "，发音标记为"
HIC "$B$" NOR "。其余颜色
符号可查看(" HIY "help nick" NOR ")绰号设定。\n
使用(" HIY "test" NOR ")为测试准备显示的信息，当使用这个命令时
信息只有使用者能够看到。

————————————————————————
\n");
                set("value", 0);
                set("rank", HIY "【调试信息】" NOR);
        }
}

void init()
{
        add_action("do_msn", "msn");
        add_action("do_set", "setrank");
        add_action("do_test", "test");
}

int do_set(string arg)
{
        string msg;
        object me = this_player();

        if (! arg)
                return notify_fail("当前仪器以" + query("rank") + "作为"
                                   "标题，你打算设定什么新信息标题？\n");

        if (arg == "none")
        {
                set("rank", HIY "【调试信息】" NOR);
                write("你将信息标题重置了。\n");
                return 1;
        }

        msg = arg;

        if (CHINESE_D->check_length(msg) > 20)
                return notify_fail("信息标题不宜过长。\n");

        if (strlen(filter_color(msg)) > 30)
                return notify_fail("信息标题不宜过长。\n");

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);

        set("rank", msg + NOR);
        write("你设定好了信息标题。\n");
        return 1;
}

int do_test(string arg)
{
        string msg, chat;
        object me = this_player();

        if (! arg || arg == "")
                msg = WHT + me->name(1) + WHT "[" +
                      me->query("id") + "]：……";
        else
                msg = arg;

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);
        msg = replace_string(msg, "$B$", BEEP);
        msg = replace_string(msg, "$N", me->name(1));
        msg = replace_string(msg, "$I", "[" + me->query("id") + "]");

        chat = query("rank") + NOR + msg + HIG "「调试中」\n" NOR;
        write(chat);
        return 1;
}

int do_msn(string arg)
{
        string msg, chat;
        object me = this_player();

        if (! arg || arg == "")
                msg = WHT + me->name(1) + WHT "[" +
                      me->query("id") + "]：……";
        else
                msg = arg;

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);
        msg = replace_string(msg, "$B$", BEEP);
        msg = replace_string(msg, "$N", me->name(1));
        msg = replace_string(msg, "$I", "[" + me->query("id") + "]");

        chat = query("rank") + NOR + msg + NOR "\n";

        shout(chat);
        write(chat);
        return 1;
}

int query_autoload()
{
        return 1;
}
