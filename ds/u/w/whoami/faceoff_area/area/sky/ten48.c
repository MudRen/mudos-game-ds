#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"���ɲ���"NOR);
 set("long",@LONG
�A��J�F���~�A�ש�ݨ�F�@�ӹ��骺�F��A�A���e��
�O�@�y���¡A�|�|��誺���p�@��ç��A�W���]���@�Ӹ�
�q�@�˪������A���@�˪��O�W���躡���ݰ_�ӫܦ��¤O����
��G��A�A�}�l�Ҽ{�n���n�h�I(touch)���A����������O�@
�ǻᬰ�S�����J��A�A���M�o�{�@�ӹ�ڪ����D�A�A�n���
�X�h�O.....?
LONG
    );
set("item_desc",([
        "����" : HIG"�����D������A�o�ӻ����i�H���A�Pı��@�ѫܱj���O�q�A���A�Q�I(touch)��...\n"NOR,
      "�J��" : HIG"�A�o�{�J��W���@�Ӥ��ө��㪺�����A�ݰ_�ӥi�H���U(press)���ˤl....\n"NOR,
]));

set("no_clean_up",0);
set("light",1);
 setup();
}

void init()
{
        add_action("do_press","press");
      add_action("do_touch","touch");

}
int do_press(string arg)
{
        object me, p;
       string a;
        object room = environment(this_player());
        me = this_player();
            if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡�G press <�F��> .\n");
   if( a!="����" )
                return notify_fail(" �o�̨S���o�تF��!\n");
        if(room->query("take_leg") == 0)
        {
                message_vision(HIC"$N���U�J��W�������A���M�@�Өƪ�����F$N�����W�C\n"NOR  ,me);
                p=new(__DIR__"eq/uchimaha_gloves.c");
                p->move(this_player());
                room->set("take_leg",1);
        }
        else
        {
                tell_object(me,HIR"�A�o�{���������U�h�A�j���O�G�٤F�a....\n"NOR);
        }
        return 1;
}

int do_touch(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten44");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n�IĲ����?\n");
        if( a!="����" )
                return notify_fail("���o�تF���?\n");
        message_vision(HIW"���M�@�ӵ��f��i�F�o�ӵL�����Ŷ��A$N�Q�]���i�h�F...!! \n"NOR,me);
          me->move(where1);
        return 1;
}



