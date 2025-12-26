import numpy as np

def sigmoid_function(x):
    return 1/(1+np.exp(-x))

def log_loss(probability, observation):
    eps = 1e-15
    probability = np.clip(probability, eps, 1-eps)
    return -(np.dot(observation.T, np.log(probability))+np.dot((1-observation.T), np.log(1-probability)))


#Function name: logistic_regression(data, learning_rate, iterations)

# Description:
#     Computes the log-odds of an event as a linear combination of one or more independent variables by gradient descent.

# Parameters:
#     *   `data` (dictionary): key- tuple containing values of data points. value- boolean True or False.
#     *   `learning_rate` (float): controls step size of gradient descent.
#     *   `iterations` (float): number of cycles of fine tuning.

# Returns:
#     (Array(features*1)): Coefficents of each feature in the linear combination.
#     (Float): Constant in linear combination.

# Raises:
#     (Exception): Invalid input data. Dictionary keys not of equal length.
#     (Exception): Invalid input data. Dictionary values not boolean.

# Example:
#     w,b = logistic_regression(d,0.004,5000)
#     print(w).
#     print(b).



def logistic_regression(data, learning_rate, iterations):
    observations = 0
    X = []
    Y = []
    for key in data:
        if observations == 0:
            features = len(key)
        elif len(key) != features:
            raise Exception("Invalid input data.\n Dictionary keys not of equal length.")
        if type(data[key]) != bool:
            raise Exception("Invalid input data.\n Dictionary values not boolean.")
        observations +=1
        X.append(np.array(key))
        Y.append(np.array([data[key]*1]))
  #return np.array(array_of_params), np.array(array_of_values), features, observations
    X = np.array(X)
    Y = np.array(Y)
    W = np.zeros((features,1))
   #return W
    B = 0
    for i in range (iterations):
        Z = np.dot(X,W) + B
    #return Z
        A = sigmoid_function(Z)
        Cost = np.sum(log_loss(A,Y))/observations
    #return Cost
        dW = np.dot(X.T , A-Y)/observations
        dB = np.sum(A-Y)/observations
    #return dW, dB
        W -= learning_rate*dW 
        B -= learning_rate*dB
        #print(f"Cost function: {Cost} for the {i+1}th iteration.")
        if i == 0:
            initial_cost = Cost
    print(f"Cost function has decreased {initial_cost/Cost} times.")
    print()
    print(f"Initial cost: {initial_cost}")
    print(f"Final cost: {Cost}")
    return W,B




