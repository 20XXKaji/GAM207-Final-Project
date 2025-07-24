// MyPlayerCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayerCharacter.generated.h"

// Forward declare the classes we will use
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
class AMyProjectile; // Forward declaration for our projectile class
struct FInputActionValue;

UCLASS()
class FINAL_PROJECT_PARTI_API AMyPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// --- INPUT ---
	// The Input Mapping Context to use
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* PlayerMappingContext;

	// The Input Action for moving
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	// The Input Action for looking
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	// The Input Action for firing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* FireAction;

	// --- COMPONENTS ---
	// Spring Arm to position the camera behind the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;

	// The player's camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;

	// --- FIRING ---
	// The projectile class to spawn. UPROPERTY(EditDefaultsOnly) means we can set this in the Blueprint.
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<AMyProjectile> ProjectileClass;

	// The location to spawn the projectile from (relative to the camera)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FVector MuzzleOffset;


	// --- HANDLER FUNCTIONS ---
	// Function to handle move input
	void Move(const FInputActionValue& Value);

	// Function to handle look input
	void Look(const FInputActionValue& Value);

	// Function to handle fire input
	void Fire();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};