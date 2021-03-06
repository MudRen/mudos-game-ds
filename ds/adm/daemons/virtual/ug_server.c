// underground virtual room object compiler

#define GROUND_ROOM "/std/room_ob"

int query_prevent_shadow() { return 1; }

object compile_object(string s) {

   object underground,ground;

   if (file_size(s+".ug") >0)
   {
   	return 0; //實際檔案存在
   }
   s+=".c";
   seteuid(creator_file(s));
   underground = new(GROUND_ROOM);
   underground->set_exit("climb",s);
   if(ground = find_object(s)) underground->set("short",ground->query("short")+"的地下");
   else underground->set("short","地層中");
   return underground;
}

