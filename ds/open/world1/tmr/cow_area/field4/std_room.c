#include <dbase.h>
#include <ansi.h>
inherit ROOM;

void change();

void create()
{
  seteuid(getuid());
  setup();
}

void init()
{
  object me = this_player();

  ::init();
  set("no_horse_member",1);
  
  if( !userp(me) ) return;
  set("outdoors","land");
  change();// ���� long 
  if( environment(me)->query_temp("stop_creat") ) return;

  // �۰ʲ��� MOB
  remove_call_out("creatmob");
  call_out("creatmob", 1, me);
}

void creatmob(object me)
{
 int amount=0;
  string file;
  object c_mob, *inv;
  mixed *mob;

  if( !me || environment(me) != this_object() ) return;


if( random(20) )
    file = __DIR__"../npc/npc10.c";// �u�|�s�X�u�����v
else
    file = __DIR__"../npc/npc11.c";// �s�X�u���������v
  if( mob = filter_array(children(file), (: clonep :)) ) amount += sizeof(mob);


   if(amount > 5)
  {
    if( !random(3) ) tell_room(this_object(),"�o�̦��G���ǭ��j��ʡC\n");
    return;
  }

  inv = all_inventory(this_object());

if( sizeof(inv) > 15 ) {
if( !random(4) ) tell_room(this_object(),"�o�̦��G���ǭ��j��ʡC\n");
return;
}

    if( random(100) < 70 ) {
    if( !random(3) ) tell_room(this_object(),"�o�̦��G���ǭ��j��ʡC\n");
return;
    }

  c_mob = new_ob(file);
  c_mob->move(this_object());
  c_mob->set("startroom", base_name(this_object()));
  
  tell_room(this_object(),"�����M�X�{�F�@" +c_mob->query("unit")+c_mob->query("name")+ "�C\n");
  return;
}

void change()
{
  string *str = ({
@LONG
���W�ͪ����A�઺����A�a��s��A�@��L�ڡA
�b�o������W�A���ۼư������A�ή���A�Ϊ����A�δ�
�šA���p������ģ�ۮ��i����A�N��촺���I��o����
�Ӧ��C
LONG,
@LONG
�o�����P���誺�ѻڳs���@�u�A�A��b�����Q��
�����h�j�A�u�ຩ�L�ئa���¦P�@�Ӥ�V���h�C
LONG,
@LONG
�A���B�b�@����줧�W�A�|�P�����󰪤j�L�H�A�u
���Ѧa�@��A�ĤJ�b���誺�a���u�W�A�Ať�����񤣮�
�Ǩӭ��V���~�����s�n�C
LONG,
@LONG
�A�Ө�F�@�Ӥj���A�E�D�����q�A���p��p�j
�@�A��A�~�F�@���I�A�w�F�w���A�o�{��Ӧ��a�v�۷�
�a���l���_�ޡC
LONG,
@LONG
�A�Ө�F�@���s��L�ڪ����A�@�K�������H�ۭ�
���߰ʡA�p������_��ۡA���A���p�m����@�������
���C
LONG,
@LONG
�o�̬O�@����o�o�����O�A�񲴱�h���p�@�����
�����A�����u���A�[���O�H���t���ɡC
LONG,
@LONG
��A�Ө�o���L����ڪ����ɡA���M�o�{�|�P�u
�ѤU�A���I�v�A�A�񪺫C���H�ۨG�D���}�����k�n�\�A
�Φ����@���������[�����j���A�A���ߦ��G�]���w��
���H�ۯB�ʡA�Ԥ���Q�n�n���󦹨Өɨ��o����������
�s�C
LONG
});

  set("short", HBK"�շt�������"NOR);
  set("long",str[random(sizeof(str))]);
  return;
}


