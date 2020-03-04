// spell.c

#include <ansi.h>
#include <dbase.h>

mapping spells;
mapping spell_learned;
mapping spell_map;

mapping query_spells() { return spells; }
mapping query_learned_spell() { return spell_learned; }

void set_spell(string spell, int val)
{
	if( !find_object(SPELL_D(spell))
	&&	file_size(SPELL_D(spell)+".c") < 0 )
		error("F_SPELL: No such spell (" + spell + ")\n");

	if( !mapp(spells) ) spells = ([ spell: val ]);
	else spells[spell] = val;
}

int delete_spell(string spell)
{
	if( mapp(spells) ) {
		map_delete(spells, spell);
		if( mapp(spell_learned) ) {
			map_delete(spell_learned, spell);
			return undefinedp(spell_learned[spell]);
		}
		return undefinedp(spells[spell]);
	}
	return 0;
}

// This function 'map' a spell <spell> to another spell <mapped_to>.
// If 2nd argument not given, cancel the mapped spell <spell>.
varargs void map_spell(string spell, string mapped_to)
{
	if( !mapped_to && mapp(spell_map) ) {
		map_delete(spell_map, spell);
		return;
	}

	if( !find_object(SPELL_D(spell))
	&&	file_size(SPELL_D(spell)+".c") < 0 )
		error("F_SPELL: No such spell (" + spell + ")\n");

	if( !mapp(spells) || undefinedp(spells[mapped_to]) )
		return;
		
	if( !mapp(spell_map) ) spell_map = ([ spell: mapped_to ]);
	else spell_map[spell] = mapped_to;
}

string query_spell_mapped(string spell)
{
	if( mapp(spell_map) && !undefinedp(spell_map[spell]) )
		return spell_map[spell];
	return 0;
}

varargs int query_spell(string spell, int raw)
{
	int s,j,k,l=0;	
	string *eff_limbs;
	s = query_temp("apply/" + spell);
	if( mapp(spells) )
	{
		if(raw==1) return spells[spell];
		s += spells[spell] ;
		if(raw==2)
		{
			eff_limbs=query("limbs_effect/skill");
 			j=sizeof(eff_limbs);
 			if(j)
 			{
 				for(k=0;k<j;k++) l+=query("wound/"+eff_limbs[k]);
 				l/=j;
 				s = s - (s * l)/110;
 			}
			return s;
		}
		if( mapp(spell_map) )
			s += spells[spell_map[spell]];
		eff_limbs=query("limbs_effect/skill");
 		j=sizeof(eff_limbs);
 		if(j)
 		{
 			for(k=0;k<j;k++) l+=query("wound/"+eff_limbs[k]);
 			l/=j;
 			s = s - (s * l)/110;
 		}
	}
  return s;
}

mapping query_spell_map()
{
	return spell_map;
}

int spell_death_penalty()
{
	string *sk;
	int i;

	if( wizardp(this_object()) || !mapp(spells) ) return 0;

	sk = keys(spells);
	if( !mapp(spell_learned) )
		for(i = 0; i<sizeof(sk); i++) {
			spells[sk[i]]--;
         if( this_object()->query_temp("killer") )
           	spells[sk[i]] = spells[sk[i]] - 3 - random(3);
			if( spells[sk[i]]<0 ) map_delete(spells, sk[i]);
		}
	else
		for(i = 0; i<sizeof(sk); i++) {
			if( (int)spell_learned[sk[i]] > (spells[sk[i]]+1) * (spells[sk[i]]+1) / 2 )
				map_delete(spell_learned, sk[i]);
			else {
				spells[sk[i]]--;
            if( this_object()->query_temp("killer") )
           	   spells[sk[i]] = spells[sk[i]] - 3 - random(3);
				if( spells[sk[i]]<0 ) map_delete(spells, sk[i]);
			}
		}
	spell_map = 0;
	return 1;
}

varargs void improve_spell(string spell, int amount, int weak_mode)
{
	int integ,maxlevel,rate;

	if( !find_object(SPELL_D(spell))
	&&	file_size(SPELL_D(spell)+".c") < 0 )
		error("F_SPELL: No such spell (" + spell + ")\n");

	if( !weak_mode || !userp(this_object()) )
	{
		if( !mapp(spells) ) spells = ([]);
		if( undefinedp(spells[spell]) ) spells[spell] = 0;
	}
	
	rate=random(12);
	if(rate <2 ) return;
	else if(rate<4 && amount >1) amount=1;
	else if(rate <6  && amount >2) amount=amount/2+1;
	
	//���ŭ���
	switch(this_object()->query("level"))
	{
		case 1:		maxlevel=19; break;
		case 2:		maxlevel=25; break;
		case 3:		maxlevel=30; break;
		case 4:		maxlevel=35; break;
		case 5:		maxlevel=39; break;
		case 6:		maxlevel=43; break;
		case 7:		maxlevel=47; break;
		case 8:		maxlevel=51; break;
		case 9:		maxlevel=55; break;
		case 10:	maxlevel=59; break;
		case 11:	maxlevel=63; break;
		case 12:	maxlevel=67; break;
		case 13:	maxlevel=71; break;
		case 14:	maxlevel=75; break;
		case 15:	maxlevel=79; break;
		case 16:	maxlevel=82; break;
		case 17:	maxlevel=85; break;
		case 18:	maxlevel=88; break;
		case 19:	maxlevel=91; break;
		case 20:	maxlevel=93; break;
		case 21:	maxlevel=95; break;
		case 22:	maxlevel=97; break;
		case 23:	maxlevel=98; break;
		case 24:	maxlevel=99; break;
		case 25:	maxlevel=100; break;
         default: maxlevel=100; break;
	}

	if(spells[spell] >= maxlevel) return;
	if(spells[spell] < SPELL_D(spell)->improve_limite(this_object()) )
	{

		// Give learning penalty to those learning too much spells.
		integ = query("int");
		if( sizeof(spell_learned) > integ )
			amount /= sizeof(spell_learned) - integ;

		if( !amount ) amount = 1;

		if( !mapp(spell_learned) ) spell_learned = ([ spell : amount ]);
		else (int)spell_learned[spell] += amount;

		if( (!weak_mode || !userp(this_object()))
		&&	spell_learned[spell] > (spells[spell] + 1) * (spells[spell] + 1) )
		{
			spells[spell]++;
			spell_learned[spell] = 0;
			if(spells[spell]>=maxlevel) tell_object(this_object(),HIG"�A���u" + to_chinese(spell) + "�v�w�g��F�ثe���ťi�׽m���̰����q�F�T(���@��"+spells[spell]+"��)\n" NOR);
			else tell_object(this_object(), HIC "�A��M��u" + to_chinese(spell) + "�v���F��`�@�h���⮩�T(���@�ܲ�"+spells[spell]+"��)\n" NOR);
			SPELL_D(spell)->spell_improved(this_object());
		}
	}
}

varargs void add_spell(string spell)
{
if( !find_object(SPELL_D(spell))
&&      file_size(SPELL_D(spell)+".c") < 0 )
       error("F_SPELL: No such spell (" + spell + ")\n");
       if( !mapp(spells) ) spells = ([ spell: 1 ]);
         else spells[spell]++;
tell_object(this_object(), HIC "�A���u" + to_chinese(spell) + "�v�g�L�@�f�m�߫�, �w�g���@�ܲ� "+spells[spell]+"�ŤF�T\n" NOR);
}
