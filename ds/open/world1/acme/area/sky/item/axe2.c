#include <ansi.h>
#define OUT_ROOM "/open/world1/acme/area/sky/room25"
inherit ITEM;
void create()
{
    set_name(HIR"����K��"NOR,({"red axe","axe"}));
        set("unit", "��");
        set("long",@LONG
�o�O�@��g���ۤѦa�U��D���@�k���A�媺�K��A���H�x�ۦU��D���@�k��
�H�A�宫�äѦa�|�����ߤ��G�A��N��ۥL�̬��Ѧa�ҥI�X�����ҤΧV�O�C
�A�q�M�a�`���ۡA���ѦۥD�a�`�P��ѩ򤤶ǨӨ����Y���ڪ���աA�B�]��
���F�Ѧa����ӧV�O�U�F�@�p�j�߭p�C
LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_blood","blood");
}

int do_blood(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="red axe" && arg!="axe"  )
        {
                notify_fail("�A�n�擄��w��?\n");
                return 0;
        }

        message_vision(HIR"$N�w�U�@�w�A��b����K��W���C\n"NOR,me);
        if(me->can_move(OUT_ROOM))
        {
                tell_room(environment(me),me->name()+"�����������L�v�L�ܤF�C\n",({me}));
                me->move(OUT_ROOM);
                write(HIG"  ��M�j����h�F�@�^���o�{�A�A�S�^��|ĳ�ǤF�C\n"NOR);
                tell_room(environment(me),HIC"��M���@�}�벴���~�A"+me->name()+HIC"�H�ۥ��~�X�{�󦹦a�C\n"NOR,({me}));
                return 1;
        } else
        {
                write("���G����Ƴ��S�o��..�Aı�o���G���ӹ�l�C\n");
                return 1;
        }
}

