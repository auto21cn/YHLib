// SN:jDbChk3ZYP<8=KFM
// ITEM Made by player(微尘:doing) /data/item/d/doing-armor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)     Fri Mar  2 15:57:34 2001
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
        set_name(HIG "北海蛟龙宝甲" NOR, ({ "armor" }));
        set_weight(9000);
        set("item_make", 1);
        set("unit", "张");
        set("long", HIG "这是以女娲补天所用之石和北海蛟龙鳞为材料打制而成的宝甲，吸纳天地\n"
                    "灵气，具有无上神通，可以抵挡世上一切攻击。然凡人不可妄动，否则立\n"
                    "遭三昧真火焚身，形神俱灭。\n" NOR);
        set("value", 1);
        set("point", 152);
        set("material", "magic stone");
        set("wear_msg", HIM "$N" HIM "展开$n" HIM "，只见碧波流转，光华四射，氤氲紫雾笼罩了四周。\n" NOR);
        set("remove_msg", HIG "$N" HIG "脱下了$n" HIG "，只见$n" HIG "化作一片碧石。\n" NOR);
        if (! check_clone()) return;
        restore();
        set("armor_prop/armor", apply_armor());
        set("armor_prop/parry", apply_armor() / 15 + 1);

        setup();
}

mixed valid_damage(object ob, object me, int damage)
{
        if (wiz_level(me) > 0)
                return ([ "damage" : -damage,
                          "msg" : HIM "只见" + name() + HIM "光华四射，绽起无数色彩，眩人夺目。\n" NOR ]);
}

int wear()
{
        object owner;

        if (objectp(owner = environment()) &&
            playerp(owner))
        {
                if (wiz_level(owner) < 1)
                {
                        message_vision(HIM "$N" HIM "展开$n"
                                       HIM "，正想披上，只听一阵雷鸣，接着便是一道\n"
                                       "闪亮的电光划过，$N"
                                       HIM "登时浑身火起，霎时被烧成飞灰。\n" NOR,
                                       owner, this_object());
                        owner->set_temp("die_reason", "被三昧真火烧成了飞灰");
                        owner->die();
                        return -1;
                }
        }

        return ::wear();
}

string long() { return query("long") + item_long(); }
