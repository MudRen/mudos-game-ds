//�t�Ϭ��ʲĤ@�W �ӯT(ttoopp) §�� -by tmr-

#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
          set_name(HIY "�Ӫ̭��n" NOR ,({ "ttoopp mask","mask"}) );
          set("long",@LONG
�t�Ϭ��ʲĤ@�W �ӯT�ұo����§���C
�o�O�@�ӥu���֦��Ӫ̤��𪺤H�~�i��W������C

�b���n���B�Y�a��A��F�G�Ӧr�u���Y�v�A
�b�k�U���]���X�Ӥp�r�u�y�v(Acme) �D�v�A
�]�����F�o�X�Ӧr�A�ϳo�ӭ��n���Ȥ��B�C
LONG
);
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��" );
                set("value",2500);
                set("valme",2);
                set("no_sac",1);
                set("armor_prop/armor", 5);
                set("armor_prop/con",1);
                  set("wear_msg","$N��W�Ӫ̭��n���ɡA���@�ذ����b�W���Pı�C\n" );
                set("remove_msg","��$N��U�Ӫ̭��n�ɡA�����b�W���Pı�y�ɮ����F�\\�h�C\n" );
        }
        setup();
}

int query_autoload() { return 1; }

