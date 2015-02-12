#ifndef PWM_H
#define PWM_H

typedef struct {
	int gpio;
	int length;
	int inverted;
} pwm_t;

// wiringPiSetup() must be called before.
void pwmSetup( const pwm_t* p );
void pwmSet( const pwm_t* p, float value );
void pwmRefresh( const pwm_t* p );

#endif
