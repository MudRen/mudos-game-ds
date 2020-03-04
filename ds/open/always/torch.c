// An example book
#include <ansi.h> // add by -alickyuen@ds-
#define DELAY 60
inherit ITEM;
void create()
{
set_name("����",({"torch"}));
set_weight(100);
set("value",10);
set("time",15);
set("unit","��");
set("long","�@�����.. �A�i�H�ϥΥ� (use torch)�C\n");
setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1) 
 {
      tell_object(me,"�o�Ӥ���w�g�N���F!\n");	
      return 1;
 }
 if(arg=="torch") //use���[�Ѽƫh�|�ǤJ���~�W�٨Ѯֹ�.
 {
  if(this_object()->query_light())
  {
   write("�o�Ӥ���w�g�b�U�N�F!\n");	
  }
   else
   {
         this_object()->set("name","����"HIR"(�U�N��)"NOR); // edit by-alickyuen@ds-
   	 this_object()->set("long","�@��U�N��������.. �A�i�H������ (use torch off)�C\n");
   	 this_object()->start_light(1);
   	 this_object()->set("no_put","�A����⥿�b�U�N�������i���̭��C\n");
   	 this_object()->set("value",2);
   	 message_vision("$N�I�U�F����C\n",me);
   	 call_out("deca",DELAY,0);
   }
  return 1;
 }
 if(arg=="off") //use �[�W�Ѽƫh�u�ǤJ�Ѽ�
 {
  if(!this_object()->query_light())
  {
   write("�o�Ӥ���èS���I�U!\n");	
  } else
  {
  	this_object()->set("name","����");
	message_vision("$N�����F����C\n",me);
  	remove_call_out("deca");
  	this_object()->set("long","�@��ιL������.. �A�i�H�ϥΥ� (use torch)�C\n");
  	this_object()->start_light(0);
  	this_object()->delete("no_put");
  }
  return 1;
 }
 return 0;
}

void deca(int flag)
{
 object ob;
 remove_call_out("deca");

 if(!this_object() ) return;
 if(!environment(this_object())) return;
 
 if(flag)
 {
	 remove_call_out("deca");
  return;
 }
 else
 {
	this_object()->set("time",this_object()->query("time")-1);
	this_object()->set("long","�@��U�N��������.. �A�i�H������ (use torch off)�C\n"
	+"�o������٥i�H�ϥ�"+this_object()->query("time")+"�����C\n");
	if(this_object()->query("time")>0)	call_out("deca",DELAY,0);
	else 
	{
	 if(living(environment(this_object())))
  		message_vision("$N���W������]���N���Ӻ��������F�C\n",environment(this_object()));
  		else tell_room(environment(this_object()),"����]���N���Ӻ����F�C\n");

	 ob=new("/open/always/badtorch");
	 ob->move(environment(this_object()));
	 destruct(this_object());
	}
   	return;
 }
   return;
}

void water_effect()
{
	object ob;
	if(query("time")<1) return;
	remove_call_out("deca");
	if(this_object()->query_light())
	{
		message_vision("���⪺���Q���������F�C\n",this_object());
		this_object()->start_light(0);
	}
	ob=new("/open/always/badtorch");
	ob->set_name("�㱼������",({"torch","badtorch"}));
	ob->set("long","�@���㱼������C\n");
	ob->move(environment(this_object()));
	destruct(this_object());
	return;
}
