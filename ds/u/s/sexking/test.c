#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"�쮦���u�@��"NOR);
        set("long", @LONG
�o�̴N�O�쮦���u�@��, �o�̧N�����o�F, �A���T�y����F�ָʶi
��, ���M�o�ɧA�i���ܦ��@���B�J�F, �o���ж������\�ۤ@�i�B�J���
�����줽��, �줽��e���ִȤw�g���B, �b�ж����t�@���٦��@�Ӥ���
, �W���}�ۤ@�������B�B, ��رi���O, �~�M���X�����Z�M�_����, �A
���T�h��, �o�Ӥu�@�Ǫ��D�H�O���O�믫�f�|�]�X�Ӫ�...
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "out" : __DIR__"workroom",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);  // ����recall�]�i�H�R��
        set("no_kill",1);  // ���|���԰��]�i�H�R����
        setup();
}
void init()
{
  object me;
  
  ::init();
  if( interactive(me = this_player()) && !me->is_fighting())
  {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
}
void hi(object me)
{
object robe;
if(!objectp(robe=present("robe",me) ) )
{
        message_vision(HIC"$N�@�i�ӳo��..�K�N���������o��...�C\n"NOR,me);
        me->receive_damage("hp",30); //�]���N�ҥH��hp
        call_out("cold",10,me);
        return;
}
else
{
message_vision(HIG"$N��M�o�{�o�̧N�����o�F,���]����ۥָʫO�x�ҥH�èS���jê�C\n"NOR,me);
return;
}
}
void cold(object me)
{
     if(!me) return;
     message_vision(HIC"$N�P��V�ӶV�N...�p�G����ӥi���H���F���_�Ӫ���..�i��|�Q�N�����C\n"NOR,me);
     me->receive_damage("hp",30);
     call_out("cold2",7,me);
     return;
}
void cold2(object me)
{
     if(!me) return;
     message_vision(HIC"$N�w�g�L�k�伵�o�اC�ŤF.�A�����}�o���ܤ@�w�|�ᦺ��.�C\n"NOR,me);
     me->receive_damage("hp",60);
     call_out("cold3",8,me);
     return;
}
void cold3(object me)
{
     if(!me) return;
     message_vision(HIR"�������A�w�g���ᦨ�B�F.�֥��h�N�ѤF....�C\n"NOR,me);
     me->set_temp("freeze",1);
     call_out("cold4",30,me);
     return;
}
void cold4(object me)
{
     if(!me) return;
     message_vision(HIC"�̫�$N�������F�B...���W�F����..�û��I�ΤF�C\n"NOR,me);
     me->set_temp("temp/death_type",HIC"[����F]"NOR);
     me->die();
     return;
}

 

