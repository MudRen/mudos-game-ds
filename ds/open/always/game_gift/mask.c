#include <armor.h>
#include <ansi.h>

inherit MASK;

void create()
{
	set_name(HIY"����ɭ�"NOR, ({"moon mask" ,"mask" }));
	set_weight(3000);
	set("long", @long
�o�O�ӤF�d�~������ɨ�s��������A�㦳���_���O�q�A�u�n�л\�b�y�W�A�۵M�|�P�л\���H�����@��C

�ݤȸ`���~ By -Alickyuen@The.Dream.Of.Seven-
-���~�W�ٷP�ª��aWatermoon@The,dream.of.seven����-
long);
	set("unit", "��");
	set("value", 0);
        set("no_put", 1);
	set("no_give", 1);
        set("armor_prop/armor", 5);
        set("armor_prop/con", 3);
	set("armor_type", "mask");

	setup();
}

int query_autoload() { return 1; }

