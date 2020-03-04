// ��s���: 2003.06.13	�ק�H: Shengsan@ms2.url.com.tw �ק�N��: sV1
#include <path.h>
#include <ansi.h>
#include <command.h>
inherit ROOM;

void create()
{
	set("short", HIY"�j���ک�"NOR);
	set("long", @LONG
�o�өж��̭��R���F�O�H�h�����𮧡C���ª��|���������F�X�i
���O���A�𨤪��[�l�W����o�ȳʩM�X���x�����ѡC���᱾�ۤ@������A
�o�̪��G�m�M�\�]���H���ئ^��L�h���Pı�A�i������γ����j�}�}�a�F
�o�̷��ɪ���^�C�F�䨤�����i�[��(Bed),�ɬW�|�������ġA�H�K�Ы��a
���A�b���ΡC

LONG
	);

	set("exits", ([ /* sizeof() == 1 */
 "west" : __DIR__"hall2",
	]) );
	set("item_desc", ([
		"bed": "�@�i��s����o�j��, �Ѯȫȥ�(sleep on bed)���ΡC\n",
		"�[��": "�@�i��s����o�j��, �Ѯȫȥ�(sleep on bed)���ΡC\n",
	]) );
	set("light",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}

void init()
{
 add_action("do_sleep","sleep");
}

int do_sleep(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file,name;
 me=this_player();
 if(!arg) return 0;
 if(me->query_temp("ride"))
 {
 	write(" �A�M�۪F�����??\n");
 	return 1;
 }
 if(me->is_ghost())
 {
 	write(HIW"  ����A�n�W�ɮ�, �@�ѱy�y���n���Ǩ�:  ���O���ݭn��ı���C\n"NOR);
 	return 1;
 }
 if(me->is_busy())
 {
 	write("�A�W�@�Ӱʧ@�٨S�����C\n");
 	return 1;
 }
 if(sscanf(arg, "on %s", arg)==1)
 {
  if(arg=="bed")
  {
   if(name=this_object()->query_temp("on_use"))
   {
   	if(name == me->query("name")) write("�A�w�g�b�ɤW��ı�F�C\n"NOR);
   	else write(HIW"����A�n�W�ɮ�,"+name+"�ߨ�@�}��A���ɤU�C\n"NOR);
   	return 1;
   }
   /* sV1 �ഫ�ɪŧאּ���ᱼ���~
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if(sscanf(file,"/open/world1/%s",buffer1)!=1
     && sscanf(file,"/open/always/%s",buffer1)!=1 )
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   �ഫ�ɪŧאּ���ᱼ���~ sV1 */
   this_object()->set_temp("on_use",me->name());
   call_out("empty",8);
   me->start_busy(6);
   me->disable_player(" <���Τ�>");
   tell_room(this_object(),me->name()+"���W�F��, ���F���i�y, �}�l�I�I�j�ΤF�_�ӡC\n",({ me }));
   //sV1 message("system", "�A��U�@�Ǧh�l�����~, ���W�F��, ���F���i�y, �}�l�I�I�j�ΤF�_�ӡC\n",me);
   message("system", "�A���W�F��, ���F���i�y, �}�l�I�I�j�ΤF�_�ӡC\n",me);//sV1
   call_out("step1",3,me);
   call_out("step2",8,me);
   call_out("step3",10,me);
   return 1;
  } 
 }
 else return 0;
}

void empty()
{
 this_object()->delete_temp("on_use");
}

void step1(object me)
{
 if(!me) return;
 message("system", "\n�A�Pı���Ǫ��n�����G�V�ӶV��.. �N�ѶV�ӶV�ҽk..\n\n",me);
 me->set_temp("block_msg/all", 1);
 message_vision("�ɤW��$N�o�X�}�}�����I�n...\n",me);
}

void step2(object me)
{
 if(!me) return;
 this_object()->delete_temp("on_use");
 message_vision("�[�ɩP�򺥺��x�_�@����Ŧ⪺����, �@�}�{�{����, $N��M�q�ɤW�����F�C\n",me);
 me->move(TMR_PAST"area/hotel");
 me->set("startroom",TMR_PAST"area/hotel");
 me->save();
 me->set_temp("block_msg/all", 0);
 message("system", "�@�}�I�R����, �A�Pı�P��S�������x�F�_�ӡC\n\n",me);
 me->set_temp("block_msg/all", 1);
 message_vision("�b�Ť���M�X�{�@���Ŧ⪺���y, $N�H�ۥ��y�w�w���U�C\n",me);
}

void step3(object me)
{
 if(!me) return;
 me->revive(1);
 me->command("look");
}