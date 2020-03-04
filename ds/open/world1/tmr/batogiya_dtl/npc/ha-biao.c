#include <npc.h>
#include <ansi.h>

#define TIMEC 120       // �}��ɶ�

void create()
{
        set_name( "���t", ({ "ha biao" , "biao" }) );
        set("long",@long
���t�@�ݴN���D�O�b������j���A�K�ª��ֽ����S�X�L�����٦ת���ءC
�L�O�Ů��������A�����������ڦ��_�Ȧ@�X�ꪺ�n���Ԩ�a
�A�p�z�Q�n�f��A�нT�w�A�w�R�n��A�h�A�n��Y�i�C(enter �Ů���)
long
);
    set("no_fight",1);
        set_race("strength");
        set("age", 40 );
        set( "title" , "�Ů������" );
        setup();
        call_out("start_ship2" , TIMEC,this_object());  // TIMEC ���}��
}

void init()
{
        if( environment()->query("where")=="batogiya_dtl" )     {
                add_action("do_enter","enter");
                return;
        } 
        if( environment()->query("where")=="duli_port" )        {
                add_action("do_enter2","enter");
                return;
        } 
}
int do_enter(string arg)
{
        // �n���� �� ������
        object me=this_player();
        object ticket;
        
        if( arg != "�Ů���" ) return 0;
        
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S���ŵn��C\n");
        if( !objectp( (ticket=present("_OBJECT_DTL_BOAT_TICKET_",me) ) )  )
        {
                message_vision(CYN "���t����צ�F$N���h���A���D�G�u�A�èS����A�Q�n����W��H�H�v\n" NOR,me);
                return 1;
        }
        message_vision(CYN "$N�q�f�U�̮��X�F�@�i��A�浹�F���t�������A�M��n�W�F�u�Ů����v�C\n" NOR,me);
        tell_room(environment(me),me->query("name")+"�֨B�a�n�W�F�n���f�C\n",me);
        destruct(ticket);       // �S���
        me->move("/d/batogiya_dtl/boat/map_9_11");      //�n��
        return 1;
}

int do_enter2(string arg)
{
        // ������ �� �n����
        object me=this_player();
        object ticket;

        if( arg != "�Ů���" ) return 0;

        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S���ŵn��C\n");
        if( !objectp( (ticket=present("_OBJECT_DTL2_BOAT_TICKET_",me) ) )  )
        {
                message_vision(CYN "���t����צ�F$N���h���A���D�G�u�A�èS����A�Q�n����W��H�H�v\n" NOR,me);
                return 1;
        }
        message_vision(CYN "$N�q�f�U�̮��X�F�@�i��A�浹�F���t�������A�M��n�W�F�u�Ů����v�C\n" NOR,me);
        destruct(ticket);       // �S���
        me->move("/d/batogiya_dtl/boat/map_9_11");      //�n��
        tell_room(environment(me),me->query("name")+"�֨B�a�n�W�F�n���f�C\n",me);
        return 1;
}

/*      �q�n���� �X�o   */
void start_ship(object me)
{
        if(!environment(me) ) return;
        
        message_vision(HIG "$N�j�n���D�G�u��n�}��������F�A�j�٨�Фp�ߤF�I�I�v\n" NOR,me);
        message_vision(CYN "$N�֨B���W�F�Ů����C\n" NOR,me);
        me->move("/d/batogiya_dtl/boat/map_9_11");      //�n��
        tell_room(environment(me),me->query("name")+"�֨B�a�n�W�F�n���f�C\n",me);

        /* ���]��W�u�n���f�v���X�f */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
        ]));
        
        call_out("on_duli_port" , 60 , me);     // 60 ���������

        return;
}

/*      ��F������      */
void on_duli_port(object me)
{
        //  ���t ���s�b�Ŷ���..
        if(!environment(me) ) return;
        
        message_vision(HIG "$N�j�n���D�G�u�������F�I�I�A�n�U��ȫȽЧ֧a�C�v\n" NOR,me);
        message_vision(CYN "$N�j�B���U�F������f�C\n" NOR,me);
        /* ���]��W�u�n���f�v���X�f */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
                "down" : "/d/duli_port/duli_port",
        ]));    
        
        me->move("/d/duli_port/duli_port");     //������
        tell_room(environment(me),CYN "�Ů����C�C�a�a��F����A���t����q��W���F�U�ӡC\n" NOR,me);

        call_out("start_ship2" , TIMEC , me);   // 300 ���}��

        return;

}

/*      �q������X�o    */
void start_ship2(object me)
{
        //  ���t ���s�b�Ŷ���..
        if(!environment(me) ) return;
        
        message_vision(HIG "$N�j�n���D�G�u��n�}���n���ԤF�A�j�٨�Фp�ߤF�I�I�v\n" NOR,me);
        message_vision(CYN "$N�֨B���W�F�Ů����C\n" NOR,me);
        me->move("/d/batogiya_dtl/boat/map_9_11");      //�n��
        tell_room(environment(me),me->query("name")+"�֨B�a�n�W�F�n���f�C\n",me);

        /* ���]��W�u�n���f�v���X�f */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
        ]));
        
        call_out("on_whale_island",60,me);      // 60 ���X�o�������
        
        return;
}

/*      ��F�H���q      */
void on_whale_island(object me)
{
        //  ���t ���s�b�Ŷ���..
        if(!environment(me) ) return;
        
        message_vision(HIG "$N�j�n���D�G�u�n���Ԩ�F�I�I�A�n�U��ȫȽЧ֧a�C�v\n" NOR,me);
        message_vision(CYN "$N�j�B���U�F�n���Դ�f�C\n" NOR,me);
        /* ���]��W�u�n���f�v���X�f */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
                "down" : "/d/batogiya_dtl/map_7_8",
        ]));
        
        me->move("/d/batogiya_dtl/map_7_8");
        tell_room(environment(me),CYN "�Ů����C�C�a�a��F����A���t����q��W���F�U�ӡC\n" NOR,me);

        call_out("start_ship",TIMEC,me); // 300 ���}��X�o�������

        return;

}

