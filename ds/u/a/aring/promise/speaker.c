// ���ܥ@�ɡO���O�O�������D����
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>
string *msgs=({
HIW"�{�b�C������ﭲ�A����ĳ�ΨǴ�ĳ�̡A��Post�b�¤ѼӪ��O�I�I"NOR,
HIW"�]Help�ɦ��ǳ\\���¡A�ҥH�x�X��Ѫ��a��������s�A���N�̤W�u��Promise�I�I"NOR,
HIW"��Mud���l�A�]�n�`�N����P���d�ADs�Ův���ߦU�쪱�a�I�I"NOR,
HIW"�зs��h�h�Q��Newbie�m�\\�ϡA�H�K�ֳt�����I�I"NOR,
HIW"���o�ͥ���Bug�A�Ш��tReport Bug�A���Ův����Ĥ@�ɶ����h���Τl�I�I"NOR,
HIW"�y�����ض��f�������w�涤�ARecall�S�O�c������w��P�饻�إq�A�H�Y�y���I�I"NOR});
void create()
{
        set_name(HIY"�C��j�n��"NOR, ({"ds speaker"}));
        set("gender", "�k��" );
        set("age", 13);
        set("title", HIC"�j�n���x���H"NOR);
        set("nickname", HIG"�L�����n���H�F���H"NOR);
       set("long", "�N��Promise�o���@���L�Q����!!\n");
       set("no_kill",1);
       set("no_fight",1);
       setup(); 
      remove_call_out("msg");
       call_out("msg",600);
      }
void msg()
{
string msgs=msgs[random(sizeof(msgs))];

     message("world:world1:vision",HIW"\n�i"HIM"�C��ֳ�"HIW"�j�G"+ msgs +"\n\n"NOR,users());
      
      }


