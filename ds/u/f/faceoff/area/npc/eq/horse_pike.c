#include <weapon.h>
#include <ansi.h>
inherit PIKE;

void create()
{
        set_name(HIW"�ﰨ�j"NOR, ({ "unicorn-horse pike", "pike" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 16000);
               
                set("long", 
"�ڻ� , �o��j�O�Ӥǰ����y�� , ���O�o�ǰ������ӫo�W�G�`�H�ү�Q������\n�e��ۤv���﨤��F�U�� , �μL�⨤��Ϊ���۲k���b�@�_ , �ӳo�ǰ��N�O�j�N�ǻ��� �Q��C"
                );
                set("wield_msg",HIG "$N���_�⤤��$n , �y�ɦǨF���_ , �U���b�ˡC\n"NOR); 
                set("unwield_msg",HIG "$N��U�⤤��$n , ���F�]�����������@�a�C\n"NOR_;                
        }
     init_pike(68);
        setup();
}