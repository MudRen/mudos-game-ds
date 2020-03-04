// An example book
#define DELAY 60
inherit ITEM;
void create()
{
set_name("��~�ϫ��C���o�;�",({"phosphorescence lighter","lighter"}));
set_weight(150);
set("value",20);
set("time",15);
set("unit","�y");
set("long","�@�y�ѹ�~���q�bA.U411�~�Ҭ�o���C���o�;� (use lighter)�C\n");
setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1) 
 {
      tell_object(me,"�o���C���o�;����෽�Χ��F�C\n");	
      return 1;
 }
 if(arg=="lighter")
 {
  if(this_object()->query_temp("has_light"))
  {
   write("�o�ӵo�������b�ϥΤ��C\n");	
  }
   else
   {
   	 this_object()->set("name","��~�ϫ��C���o�;�(�ϥΤ�)");
   	 this_object()->set("long"," �@�y�ѹ�~���q�bA.U411�~�Ҭ�o���C���o�;�,�åB�S�����W,�A�i�H������ (use lighter off)�C\n");
   	 this_object()->set_temp("has_light",1);
   	 this_object()->set("value",5);
   	 message_vision("$N�N�o�;����}�����}�C\n",me);
   	 call_out("deca",DELAY,0);
   }
  return 1;
 }
 if(arg=="off")
 {
  if(!this_object()->query_temp("has_light"))
  {
   write("�o���C���o�;��ä��b�ϥΤ��C\n");	
  } else
  {
  	this_object()->set("name","��~�ϫ��C���o�;�");
	message_vision("$N�N�o�;����}�����W�C\n",me);
  	remove_call_out("deca");
  	this_object()->set("long","�@�y�ѹ�~���q�bA.U411�~�Ҭ�o���C���o�;� (use lighter)�C\n");
  	this_object()->delete_temp("has_light");
  }
  return 1;
 }
 return 0;
}

void deca(int flag)
{
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
	this_object()->set("long"," �@�y�ѹ�~���q�bA.U411�~�Ҭ�o���C���o�;�,�åB�S�����W,�A�i�H������ (use lighter off)�C\n"
	+"�o������٥i�H�ϥ�"+this_object()->query("time")+"�����C\n");
	if(this_object()->query("time")>0)	call_out("deca",DELAY,0);
	else 
	{
	 this_object()->delete_temp("has_light");
	 this_object()->set("long","�w�g�Χ����o�����C\n");
	 this_object()->set("name","�L�෽���o����");
	 this_object()->set("value",0);
	 if(living(environment(this_object())))
  		message_vision("$N���C���o�;��]���Χ��෽�Ӻ��������F�C\n",environment(this_object()));
  		else tell_room(environment(this_object()),"�C���o�;��]���Χ��෽�Ӻ����F�C\n");
	}
   	return;
 }
   return;
}