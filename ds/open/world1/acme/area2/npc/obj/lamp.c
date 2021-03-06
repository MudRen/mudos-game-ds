#define DELAY 60
inherit ITEM;
void create()
{
set_name("油燈",({"oil lamp","lamp"}));
set_weight(100);
set("value",100);
set("time",20);
set("unit","個");
set("long","一個油燈，上頭寫著血紅兩個字「勾魂」，你可以使用它 (use lamp)。\n");
setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1)
 {
      tell_object(me,"這個油燈已經沒油了！\n");
      return 1;
 }
 if(arg=="lamp") //use不加參數則會傳入物品名稱供核對.
 {
  if(this_object()->query_light())
  {
   write("這個油燈已經在燃燒中！\n");
  }
   else
   {
         this_object()->set("name","油燈(燃燒中)");
         this_object()->set("long","一個燃燒中的油燈.. 你可以熄滅它(use lamp off)。\n");
         this_object()->start_light(1);
         this_object()->set("value",2);
         message_vision("$N點燃了油燈。\n",me);
         call_out("deca",DELAY,0);
   }
  return 1;
 }
 if(arg=="off") //use 加上參數則只傳入參數
 {
  if(!this_object()->query_light())
  {
   write("這個油燈並沒有點燃!\n");
  } else
  {
        this_object()->set("name","油燈");
        message_vision("$N熄滅了油燈。\n",me);
        remove_call_out("deca");
        this_object()->set("long","一個用過的油燈，你可以使用它 (use lamp)。\n");
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
        this_object()->set("long","一支燃燒中的油燈，你可以熄滅它 (use lamp off)。\n"
        +"這個油燈還可以使用"+this_object()->query("time")+"分鐘。\n");
        if(this_object()->query("time")>0)      call_out("deca",DELAY,0);
        else
        {
         this_object()->start_light(0);
         this_object()->set("long","一個燒完的油燈。\n");
         this_object()->set("name","沒油的油燈");
         this_object()->set("value",0);
         if(living(environment(this_object())))
                message_vision("$N身上的油燈因為沒油而漸漸熄滅了。\n",environment(this_object()));
                else tell_room(environment(this_object()),"油燈因為沒油而熄滅了。\n");
        }
        return;
 }
   return;
}
