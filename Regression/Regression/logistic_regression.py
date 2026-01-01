import numpy as np


class StandardScaler:
    def __init__(self, with_mean = True, with_std = True):
        self.with_mean = with_mean
        self.with_std = with_std

    
    def fit(self, X): #X is a np.ndarray
        X = X.astype(float)
        self.mean = X.mean(axis = 0) if self.with_mean else np.zeros(X.shape[1])
        self.std = X.std(axis =0) if self.with_std else np.ones(X.shape[1]) 
        self.std = np.where(self.std == 0, 1.0, self.std)
        self.with_mean = self.with_std = True
        return self

    def transform(self, X):
        if self.with_mean and self.with_std:
            X -= self.mean
            X /= self.std
            return X
        else: 
            raise ValueError("Fit the array before transforming.")

    def fit_transform(self, X):
        return self.fit(X).transform(X)


class LogisticRegressor:
    def __init__(self, learning_rate = 0.001, iterations = 3000, Weights = None, intercept =0,  verbose = False):
        self.learning_rate = learning_rate
        self.iterations = iterations
        self.Weights = Weights
        self.intercept = intercept
        self.verbose = verbose

    def sigmoid_function(self, x):
        return 1/(1+np.exp(-x))

    def log_loss(self, probability, observation):
        eps = 1e-15
        probability = np.clip(probability, eps, 1-eps)
        return -(np.dot(observation.T, np.log(probability))+np.dot((1-observation.T), np.log(1-probability)))

    def load_data(self, X, y):
        if isinstance(X, np.ndarray) and isinstance(y, np.ndarray) and X.shape[0] == y.shape[0]:

            X = X.astype(float)
            standard_scaler = StandardScaler()
            X = standard_scaler.fit_transform(X)
            return X, y
        else:
            raise ValueError("Input data should be in the form of two arrays.")


    def random_weights(self, rows, columns):
        self.Weights = np.random.rand(rows, columns)
        return self.Weights


    def fit(self, X,y):
        X, y = self.load_data(X,y)
        if self.Weights == None:
            self.Weights = self.random_weights(X.shape[1],1)
        
        for i in range (self.iterations):
            Z = np.dot(X, self.Weights) + self.intercept
            A = self.sigmoid_function(Z)
            Cost = np.sum(self.log_loss(A,y))/X.shape[0]
            dW = np.dot(X.T , A-y)/X.shape[0]
            dB = np.sum(A-y)/X.shape[0]
        
            self.Weights -= self.learning_rate*dW 
            self.intercept -= self.learning_rate*dB

            if self.verbose:
                print(f"The {i}th iteration.")
                print(f"The cost function is {Cost}.")

    def predict(self, X):
        X = X.astype(float)
        standard_scaler = StandardScaler()
        X = standard_scaler.fit_transform(X)

        Z = np.dot(X, self.Weights) + self.intercept
        predictions = np.round(self.sigmoid_function(Z))
        return predictions.astype(int)
            
    def compute_accuracy(self,predictions, observations):
        correct_counts = 0
        for i in range (predictions.shape[0]):
            if predictions[i, 0] == observations[i,0]:
                correct_counts +=1
        
        return 100*correct_counts/predictions.shape[0]
        #return 100

    


        
    





    


