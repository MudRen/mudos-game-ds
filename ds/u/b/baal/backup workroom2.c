#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"������A�G������"NOR);
        set("long", @LONG
���c���𮧥R���b�o�өж���, �A�P�즺�`���¯�, ���T�`�Ȫ���
���o��, ��W��ۥN��·t���Z��J�起�����Y�s, �ݨӳo�N�O�����
�ͩ^������F, �A�P�쨸�c�C�C���̦�A�����F, �b�o�ӴX�Q�B�᪺��
����, �A�i�Hť��ۤv���߸��n...
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "out" : __DIR__"workroom",
        "down" : __DIR__"npctestroom",
        "north" : __DIR__"workroom3",
        "up" : __DIR__"workroomf2-1",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("no_recall",1);  // ����recall�]�i�H�R��
        set("no_kill",1);  // ���|���԰��]�i�H�R����
        setup();
  call_other("/obj/board/baal_b" , "???");
}

void init()
{
  object me;
  
  if( interactive(me = this_player()) && !me->is_fighting())
  {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
}
void hi(object me)
{
object amulet;
if(!objectp(amulet=present("amulet",me) ) )
{
        message_vision(HIC"$N�@�i�ӳo��..�K�]�ۤߤ��ͥX���ߦӤ������o��...�C\n"NOR,me);
        me->receive_damage("hp",300); //�]���N�ҥH��hp
        call_out("cold",10,me);
        return;
}
else
{
message_vision(HIG"$N���ۤ⤤���@����, �ӨϪ����ߵy��, �H�N�����h�h, ��$N���i�H�Pı�쨸�c���`�N��$N�C\n"NOR,me);
return;
}
}
void cold(object me)
{
     if(!me) return;
message_vision(HIC"$N�P��V�ӶV�`��...�ߤ������ߺ����]���F$N�����F...�ͩR�O�}�l���}$N�����ߡC\n"NOR,me);

     me->receive_damage("hp",150);
     call_out("cold2",7,me);
     return;
}
void cold2(object me)
{
     if(!me) return;
     message_vision(HIC"$N�w�g�L�k��ܳo���ߤF.�A�����}�o���ܤ@�w�|���b�o,�����`�F��.�C\n"NOR,me);
     me->receive_damage("hp",250);
     call_out("cold3",8,me);
     return;
}
void cold3(object me)
{
     if(!me) return;
     message_vision(HIR"$N�u�ѤU�L�z���@�f��.�֥��h�N�ѤF....�C\n"NOR,me);
     me->set_temp("freeze",1);
     call_out("cold4",30,me);
     return;
}
void cold4(object me)
{
     if(!me) return;
     message_vision(HIC"�̫�$N�b���_Ÿ�ݤ��_�_���򪺦R�X�F�@�f��...���W�F����...�����ФW�F�@�h�������B..�û��I�ΤF�C\n"NOR,me);
     me->set_temp("temp/death_type",HIC"[����F]"NOR);
     me->die();
     return;
}


