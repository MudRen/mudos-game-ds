#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
	set_name(HIY"�������"NOR, ({ "moon skirt", "skirt" }));
	set_weight(3000);
	set("long", @long
�o�O�@����ժ����ȡA���o�۬X�M�����~�C�۶Ǭ���c�Q�Q�ˤ�Τ�����E�����ҽs���Ӧ����C

�ݤȸ`���~ By -Alickyuen@The.Dream.Of.Seven-
-���~�W�ٷP�ª��aWatermoon@The,dream.of.seven����-
long);
	set("unit", "��");
	set("value", 0);
        set("no_put", 1);
	set("no_give", 1);
        set("armor_prop/armor", 15);
        set("armor_prop/int", 3);
        set("armor_type", "pants");
	set("female_only", 1);

	setup();
}

int query_autoload() { return 1; }
