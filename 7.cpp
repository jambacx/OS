#include <pthread.h>

int available_resources = MAX_RESOURCES;

pthread_mutex_t lock;

int decrease_count(int count) {
  if (available_resources < count)
    return -1;
  else
    pthread_mutex_lock(&lock);
  available_resources -= count;
  pthread_mutex_unlock(&lock);
  return 0;
}

int increase_count(int count) {
  pthread_mutex_lock(&lock);
  available_resources += count;
  pthread_mutex_unlock(&lock);
  return 0;
}

/* a.Identify the data involved in the race condition.
	Hariult: available_resources ni race condition-d urtuj baina.
    
b. Identify the location (or locations) in the code where the race
condition occurs.
    Hariult: nemegdvvleh bolon horogduulah process ni 
             available_resources ni count huwisagchaar ni nemegdvvleed nogooh 
             ni horogduulj baigaaa ene ni uyd condition vvsej baih magdlaltai. 

	
c. Using semaphore or mutex lock, fix the race condition.
	Hariult: Mutex lock ashiglaj 'available_resources' 
             utgiig nemegdvvleh horogduulah uyd mute_lock hiisen.
