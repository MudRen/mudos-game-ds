#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIY"�����F��"NOR, ({ "moon necklace", "necklace" }));
	set_weight(3000);
	set("long", @long
�o�D�O�ѧl�Ǥ�����O�q�ӷһs�����@�D�šC�۶Ǩرa�b���W�A��o�������P�@�C

�ݤȸ`���~ By -Alickyuen@The.Dream.Of.Seven-
-���~�W�ٷP�ª��aWatermoon@The,dream.of.seven����-
long);
        set("unit", "��");
	set("value", 0);
        set("no_put", 1);
	set("no_give", 1);
        set("armor_prop/armor", 8);
	set("armor_type", "neck");

	setup();
}

int query_autoload() { return 1; }

void init()
{
        object me= this_player();

	if( !me) return;

        if( environment(this_object()) == me )
        {
                if( !this_object()->query_light() ) this_object()->start_light(1);
        }
	else this_object()->start_light(0);
}
