// Room: /d/gumu/obj/bed.c �H�ɧ�
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"�H�ɧ�"NOR, ({"hanyu bed","bed"}));
        set_weight(2500000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long", 
HIC"���ɬݤW�h�����q�q�צp�C�ۡA�o�O���򤤤H�H�ڴK�H�D���Z�L���_�H�ɧɡA\n"
   "�ǻ������ɥi�����󤺥~�˯f�A���^�Ѥ��ġA�p�s�k��~�D�������k���M���u��\n"
   "�l�X�O�@���A��k�X�ͤѡA���ɥ\\���i�S�A�󦳤H�����ɥi�t���Z�\\�A�j�q�_��\n"
   "�\\�׬��C\n"NOR
        );
                set("no_get", 1);
                set("no_sac", 1);
                setup();
        }
}


