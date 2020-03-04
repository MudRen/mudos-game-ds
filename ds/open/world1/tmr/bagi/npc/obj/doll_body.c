#include <ansi.h>
#define LEFT_ARM 1
#define RIGHT_ARM 2
#define LEFT_LEG 4
#define RIGHT_LEG 8
#define DOLL_HEAD 16

inherit ITEM;
string long=@LONG
�o�O�@����n���o�ӳy���G�u�������ߡA�����ۤ@�󯻬��⪺��n�A�I
��ۥզ⪺���I�A�֮z���p�Z�y��Y��X�׺����ݳ��C���o�u�O�@�㨭�ߦ�
�w�A�٤֤F�@���Y�B�Ⱖ��M�Ⱖ�}�A�γ\�A���X��������}�A�n�n��o
�զX(compose)���@�ӯu�������H�˧a�C
LONG
;

string query_long()
{
        string msg;
        int state=query("compose_state");
        if(state==0) return "";
        msg=HIC"\n�o�Ӱ����ߤW�w�g�˦��G";
        if(state & 1)   msg+=" ���u";
        if(state & 2)   msg+=" �k�u";
        if(state & 4)   msg+=" ���}";
        if(state & 8)   msg+=" �k�}";
        if(state & 16)  msg+=" �H�Y";
        msg+="�����x�F�C\n"NOR;
        return msg;
}


void create()
{
        set_name("�����W������",({"unknown body","body","DOLL_BODY"}));
        set_weight(100);
        set("unit","��");
        set("long",long   );
        set("compose_state",0);
          set("replica_ob",__DIR__"right-arm");
        setup();
}

void init()
{
        add_action("do_compose","compose");
}

int do_compose(string arg)
{
        int state;
        object com,me,doll;
        me=this_player();
        state=query("compose_state");

        if(!arg)
                return notify_fail("�A�Q�n�զX����H\n");
        if(!objectp(com=present(arg,me)))
                return notify_fail("�A���W�èS���o�ӪF��C\n");
        if(com->id("DOLL_LEFT_ARM") ) // ���u 1
        {
                if( state & 1 ) 
                        return notify_fail("�o�Ӱ����ߤw�g�˦��u���u�v�F�C\n");
                message_vision(CYN"$N��������$n�������ߪ����ӻH�U�@���@���A���\\�a���W���u�F�C\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+1);
        }
        else if(com->id("DOLL_RIGHT_ARM") ) // �k�u 2
        {
                if( state & 2 ) 
                        return notify_fail("�o�Ӱ����ߤw�g�˦��u�k�u�v�F�C\n");
                message_vision(CYN"$N��������$n�������ߪ��k�ӻH�U�@���@���A���\\�a���W�k�u�F�C\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+2);
        }
        else if(com->id("DOLL_LEFT_LEG") ) // ���} 4
        {
                if( state & 4 ) 
                        return notify_fail("�o�Ӱ����ߤw�g�˦��u���}�v�F�C\n");
                message_vision(CYN"$N�յۧ�$n�������ߪ��U�b���α��A�g�L�@�f�V�O�A���\\�a���W���}�F�C\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+4);
        }
        else if(com->id("DOLL_RIGHT_LEG") ) // �k�} 8
        {
                if( state & 8 ) 
                        return notify_fail("�o�Ӱ����ߤw�g�˦��u�k�}�v�F�C\n");
                message_vision(CYN"$N�յۧ�$n�������ߪ��U�b���α��A�g�L�@�f�V�O�A���\\�a���W�k�}�F�C\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+8);
        }
        else if(com->id("DOLL_HEAD") ) // �Y 16
        {
                if( state & 16 ) 
                        return notify_fail("�o�Ӱ����ߤw�g�˦��u�Y�v�F�C\n");
                message_vision(CYN"$N�����a�N$n�����������˸m�찲���ߪ���l�W�A���\\�a���W���H�Y�F�C\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+16);
        }
        else
                message_vision(CYN"$N�����k�����A�N�O�L�k��"+ com->name()+CYN"�˨찲���ߤW�C\n"NOR,me,com);

        set("long",long+query_long());

        if(query("compose_state")==31) { // ���������F
                doll=new("/open/always/doll");
                if(objectp(com=present("undead_item",me))) {
                message_vision(HIY"��$N���\\���꧹��㰲�H������........\n"NOR
                +HIW"���H���M�ư��@�}���ϡA�H���ƴ������F.....\n"NOR,me);
                destruct(this_object());
                return 1;
                } 
                message_vision(HIY"��$N���\\���꧹��㰲�H������........\n"NOR
                +HIW"�������������M�ե֪��w�F�ƤU�A�`���ڴڪ��`����$N�A�L�̻��D�G"
                +HIW"�u�q���N���ڸ��H�ۧA�A�O�@�ۧA�a..........�v\n\n"NOR,me);
                doll->move(me);
        log_file("static/COMPOSE_DOLL",
                sprintf("%s(%s) on compose doll at  %s\n",
                me->name(1), geteuid(me),ctime(time()) ) );

                destruct(this_object());                
        }
        return 1;
}


