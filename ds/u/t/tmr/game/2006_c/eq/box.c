// 2006/12/26

#include <ansi.h>
inherit ITEM;

int do_wehre();

void create()
{
        set_name("�c������",({"magic box","box"}) );
        set("long",@long
�o�O�@�ӯ}�ª��¥ֽc�l�A�A�ܦn�_���W�h(stand)�|�o�ͤ���ơC
long
);
        set_weight(10);
        set("unit","��");
          set("value",100);
        setup();
}

void init()
{
        add_action("do_stand","stand");
}

int do_stand(string arg) {
        object me, room, man;
        int i;
        me = this_player();
        if(me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۡC\n");
        if(arg!="box")
                return notify_fail("�A�Q�n���b���̡H\n");

        message_vision(CYN"$N�N�c��������b�a�W�A�p���l�l�a���F�W�h....\n"NOR,me);
        message_vision(YEL"$N��ۥ|�g�j�n���D�G�ڱa���o�Ӥ��O���q�c�l�A�ӬO�c�������A²�ٽc���A���i�H�w���S�t�x�a��ڰe�����ڷQ�h���a��I�I\n"NOR,me);

        message("system", 
                HIC"\n\t"+me->name()+HIC"�j�ۡu"HIY"�c��㯫�����"HIC"�v�A���l���_���W���A�̫��ܦ��Ť����@�Ӥp�I�C\n"NOR, users() );
        room = new("/open/world1/tmr/game/2006_c/cloud");
 
        i = 5 + random(5);
        while(i-->=0) {
                 man = new("/u/t/tmr/game/2006_c/oldman2.c");
                man->move(room);
        }

        me->move(room);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}


