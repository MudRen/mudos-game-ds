#include <ansi.h>
inherit NPC;
void normal_ai();

void create()
{
  set_name("�����H",({"robot"}) );
  set("long",@long
�@�ӫ���Ӧ��������H�A�Q�Υ��|�Ӥj�p���@�����l�b�w�w���ʵۡC
long);      
  set("age",10);
  set("level",23+random(2));
  set("attitude", "peaceful");
  set("unarmed",20);
  set("no_fight",1);
  set("chat_chance",2);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  setup();                
}

void normal_ai()
{
  object me,target;
  me = this_object();

  switch( random(10) )
  {
    case  0: message_vision("�����H���X�F�@�q�����G"HIG"��V�}�ɪ����֡H\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIG"�����n���潺���A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIG"���g�@�q�M�����A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIG"�X�f��V��۬��C\n"NOR,me);
          break;
    case  1: message_vision("�����H���X�F�@�q�����G"HIW"���ݯB����ɷ��H\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIW"���ӫխ����s���A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIW"�o�ݤp�|����B�A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIW"�@����b�v���C\n"NOR,me);
          break;
    case  2: message_vision("�����H���X�F�@�q�����G"HIR"��̦������K�[�A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIR"���i�v�e�R�^�n�A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIR"�������h�ū����A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIR"�̴ۨݤ���N�C\n"NOR,me);
          break;
    case  3: message_vision("�����H���X�F�@�q�����G"HIC"���ʺ�޵ޡA\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIC"���C���K���A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIC"����V���K�A\n"NOR,me);
             message_vision("�����H���X�F�@�q�����G"HIC"��U�H�@�v�C\n"NOR,me);
          break;
    case  4: message_vision("�����H���X�@���ޤl�A�o�X�n�����n���A�}�l�l���𨤪��ǹСC\n"NOR,me);
          break;
    case  5: message_vision("��M�@�}�����Z���B���n�A�q�����H�����W�u�X�F�@�������C\n"NOR,me);
          break;
    case  6: message_vision("�����H�Υ|�Ӥj�p���@�����l�C�C�a�樫�C\n"NOR,me);
          break;
    case  7: message_vision("�q�����H���W��M�_�X�@�ο@�ϡA���ߨ�Q�l������H���I��C\n"NOR,me);
          break;
    case  8: message_vision("�����H�����a���V����A�b��W��X�ƹD����~����^�Y�C\n"NOR,me);
          break;
  }
  return;
}
