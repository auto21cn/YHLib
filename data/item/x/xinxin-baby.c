// ITEM Made by player(山下美子:xinxin) /data/item/x/xinxin-baby.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 12:37:32 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m无[1;36m敌[34m战[32m衣[2;37;0m", ({ "baby" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[2;37;0m[1;31m阎罗绸[2;37;0m炼制而成的一件战衣。
连洋枪都打不透的无敌战衣，让天下所有的无耻之徒都退避三舍。这是正义的象征，是所有武林高手梦寐以求的宝贝。此物只应天上有，人间能有几回合？[2;37;0m
战衣缘上刻着一行小字：山下美子(xinxin)
");
	set("value", 2000000);
	set("point", 125);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m装备[1;35m无[1;36m敌[34m战[32m衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;35m无[1;36m敌[34m战[32m衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
