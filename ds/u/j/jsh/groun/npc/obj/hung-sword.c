#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("�M�h�Q�r�C", ({ "huge cross sword","sword" }) );
        set_weight(3200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��"); 
                set("limit_str",50);
                set("long", "
�@�`�j�o�رi���M�h�C�A��ӼC����@�ӤH�ٰ��A���λ����h��
  �F�A�Y�O���ʰ_�ӷQ���i�H�s�H�a���@�_�٦���b�C\n");
                set("value", 3500);
        }
        init_sword(55);
        setup();
}

