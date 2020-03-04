// file:   /adm/obj/simul_efun/overrides.c
#include <command.h>
nomask varargs void
shutdown(int code)
{
   object prev;
   
   seteuid(getuid(this_object()));
   prev = previous_object();
   if (geteuid(prev) != ROOT_UID) {
      if(base_name(prev) != "/obj/npc/terminater") return;
   }
    log_file("shutdown", "Game shut down by " +
      (this_player() ? capitalize(geteuid(this_player())) : ROOT_UID) +
      " at " + ctime(time()) + "\n");
   efun::shutdown(code);
}

nomask varargs object
snoop(object snooper, object snoopee) {
   
   if (file_name(this_object()) != SIMUL_EFUN_OB) return 0;
   if (file_name(previous_object()) != SNOOP_CMD) return 0;
   if (!snoopee) return efun::snoop(snooper);
   if (!wizardp(snooper)) return 0;
   if(wiz_level(snooper) < wiz_level(snoopee)) return 0;
   return efun::snoop(snooper, snoopee);
}

nomask int
exec(object to_obj, object from_obj) {
   string prev;
   if (file_name(this_object()) != SIMUL_EFUN_OB) return 0;
   prev = base_name(previous_object());
//    New = base_name( to_obj );
//    if( New != "/obj/login" || member_array("obj/user.c",
//	deep_inherit_list( to_obj ) ) == -1 )
//		return 0;
   if (prev == LOGIN_D || prev == UPDATE_CMD || prev == QUIT_CMD )
   {
      return efun::exec(to_obj, from_obj);
   }
   return 0;
}

nomask int
export_uid(object ob) {
   if (ob == master()) return 0;
   seteuid(geteuid(previous_object()));
   return efun::export_uid(ob);
}

nomask object
query_snoop(object who) {
   string prev;
   prev = geteuid(previous_object());
   if (prev != ROOT_UID && !adminp(prev))
      return 0;
   else return efun::query_snoop(who);
}

nomask object
query_snooping(object who) {
   string prev;
   prev = geteuid(previous_object());
   if (prev != ROOT_UID && !adminp(prev))
      return 0;
   else return efun::query_snooping(who);
}

nomask int
set_eval_limit(int num) {
 if ( getuid(previous_object()) != ROOT_UID ) return 0;
 efun::set_eval_limit(num);
  return 1;
}
