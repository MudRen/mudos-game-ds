#include <armor.h>

inherit SURCOAT;

inherit F_UNIQUE;


void create()

{
set_name("�}��",({"cloth"}) );


      set_weight(210);

        if( clonep() )
   
set_default_object(__FILE__);

        else {

set("long","�@�����_�����}���C");

                set("material", "cloth");

                set("unit", "��");

                set("value", 7);

        }

        setup();
}
void init()
{
       add_action("do_search","search");   
}
int do_search(string arg)
{
        object me,obj;
        me=this_player();
        obj=this_object(); 

        if (arg != "�}��" && arg !="cloth" )
                return 0;
        else
        {
        tell_object(me,"�A�J�Ӫ��ݤF�ݳo���}���A�o�{��ӳo�O���_��P�ܭ��I�I�I\n");
        obj->set_name("��P�ܭ�",({"star robe","robe"}) );

        obj->set("long",           
                 "�@�����_�����}���A�u���֦��̤~���D�����O���q���F��C\n"

                 "���������S�M�j���J�A�ӥB�R���F�������O�q�A�i���仪��\n"

                 "���A��b���W�֤]�����D�O���_���C�]���]���p���A�ҥH�~\n"

                 "�S���H���ܥ��A�ҥH�A�~����o�쥦�C\n");


      obj->set("armor_prop/armor", 7);

        obj->set("armor_prop/shield", 17);

        obj->set("armor_prop/dex", 2);

        obj->set("armor_prop/int", 2);

        obj->set("armor_prop/str", 1);

        obj->set("armor_prop/con", 1);

        obj->set("armor_prop/dodge", 7);
        return 1;
        }

}
