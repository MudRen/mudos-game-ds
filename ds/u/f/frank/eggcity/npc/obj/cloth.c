#include <armor.h>
#include <ansi.h>
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIY"�W�����ͦ�"NOR ,({ "cicada cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
�����_��O�ӫҪ������_��A�S�O�絹���\���H�A�L�����m�O�A
�ڷQ���λ��F�A�@�w�O�@�ŴΪ��C�J�M�O���ͦ�A��M�֤��F�^�b�W
���@���@�������ͤF�A���M�O�����h�ɡA���L�L���W���߫o�٬O�v�~
���W�p�A���T�O���_��A���L�ӫҬ��󤣭n�A���N�S�H���F�C
LONG
     );
        set("unit", "��");
        set("value",10000);
        set("material", "steel");
        set("armor_prop/shield",2);
        set("armor_prop/con",2);
        set("armor_prop/armor", 25);
        set("wear_msg",HIY"$N��W�F�W�����ͦ��A���Gť��F�ͥs�C"NOR);

        }
        setup();
}

