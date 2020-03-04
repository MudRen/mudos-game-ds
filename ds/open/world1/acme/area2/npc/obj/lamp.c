#define DELAY 60
inherit ITEM;
void create()
{
set_name("�o�O",({"oil lamp","lamp"}));
set_weight(100);
set("value",100);
set("time",20);
set("unit","��");
set("long","�@�Ӫo�O�A�W�Y�g�ۦ����Ӧr�u�Ļ�v�A�A�i�H�ϥΥ� (use lamp)�C\n");
setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1)
 {
      tell_object(me,"�o�Ӫo�O�w�g�S�o�F�I\n");
      return 1;
 }
 if(arg=="lamp") //use���[�Ѽƫh�|�ǤJ���~�W�٨Ѯֹ�.
 {
  if(this_object()->query_light())
  {
   write("�o�Ӫo�O�w�g�b�U�N���I\n");
  }
   else
   {
         this_object()->set("name","�o�O(�U�N��)");
         this_object()->set("long","�@�ӿU�N�����o�O.. �A�i�H������(use lamp off)�C\n");
         this_object()->start_light(1);
         this_object()->set("value",2);
         message_vision("$N�I�U�F�o�O�C\n",me);
         call_out("deca",DELAY,0);
   }
  return 1;
 }
 if(arg=="off") //use �[�W�Ѽƫh�u�ǤJ�Ѽ�
 {
  if(!this_object()->query_light())
  {
   write("�o�Ӫo�O�èS���I�U!\n");
  } else
  {
        this_object()->set("name","�o�O");
        message_vision("$N�����F�o�O�C\n",me);
        remove_call_out("deca");
        this_object()->set("long","�@�ӥιL���o�O�A�A�i�H�ϥΥ� (use lamp)�C\n");
        this_object()->start_light(0);
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
        this_object()->set("long","�@��U�N�����o�O�A�A�i�H������ (use lamp off)�C\n"
        +"�o�Ӫo�O�٥i�H�ϥ�"+this_object()->query("time")+"�����C\n");
        if(this_object()->query("time")>0)      call_out("deca",DELAY,0);
        else
        {
         this_object()->start_light(0);
         this_object()->set("long","�@�ӿN�����o�O�C\n");
         this_object()->set("name","�S�o���o�O");
         this_object()->set("value",0);
         if(living(environment(this_object())))
                message_vision("$N���W���o�O�]���S�o�Ӻ��������F�C\n",environment(this_object()));
                else tell_room(environment(this_object()),"�o�O�]���S�o�Ӻ����F�C\n");
        }
        return;
 }
   return;
}
